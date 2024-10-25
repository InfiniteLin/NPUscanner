#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口名和图标
    setWindowTitle("NPUscanner");
    setWindowIcon(QIcon("./ico/scanner.ico"));

    /* 设置背景图片 */
    //QPixmap pixmap("./image/background.jpg");
    //QPalette palette;
    //palette.setBrush(backgroundRole(), QBrush(pixmap));
    //setPalette(palette);

    // 设置textOutput的背景
    ui->textOutput->setStyleSheet("QTextBrowser { background-image: url('./ico/background.jpg'); "
        "background-repeat: no-repeat; "
        "background-position: center; }");

    // 添加一些文本内容
    ui->textOutput->setText("Hello, World! This is a QTextBrowser with a background image.");


    //连接button和slot
    connect(ui->runpy_pushButton, SIGNAL(clicked(bool)), this, SLOT(runPythonScript()));

    //设置文本框为只读，作为显示输出的框
    ui->textOutput->setReadOnly(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runPythonScript(void)
{
    QProcess* process = new QProcess();

    // 设置要执行的 Python 脚本和参数
    QString scriptPath = "./py/vuln_scan.py"; // Python 脚本路径
    QStringList arguments;                    // 参数列表
    //获取输入的ip
    arguments << ui->lineEdit->text();
    //arguments << "10.12.13.30";            // 添加你的参数

    // 启动 Python 进程并传递参数
    process->start("python", QStringList() << scriptPath << arguments);
    process->waitForFinished(); // 可选，等待脚本执行完成

    QString output = process->readAllStandardOutput();
    QString error = process->readAllStandardError();

    // 显示输出和错误信息
    ui->textOutput->append("Output:\n" + output);
    ui->textOutput->append("Error:\n" + error);
}