#include "dialtestthemecode.h"
#include "ui_dialtestthemecode.h"
#include <QDebug>

DialTestThemeCode::DialTestThemeCode(QWidget *parent):
  QDialog(parent),
  ui(new Ui::DialTestThemeCode)
{
  ui->setupUi(this);

  setWindowTitle("Test mode code");

  connect(ui->btn_cancel, &QPushButton::clicked, [ = ]()
  {
    this->close();
  });

  connect(ui->btn_clearText, &QPushButton::clicked, [ = ]()
  {
    this->ui->textEditCode->clear();
    this->ui->textEditCode->setFocus();
  });
}

DialTestThemeCode::~DialTestThemeCode()
{
  delete ui;
}

void  DialTestThemeCode::on_btn_Ok_clicked()
{
  _codeTheme.clear();

  _codeTheme = this->ui->textEditCode->toPlainText();
  qDebug() << _codeTheme;
  emit  setCodeTheme(_codeTheme);
  this->close();
}

void  DialTestThemeCode::on_btn_Apply_clicked()
{
  _codeTheme.clear();

  _codeTheme = this->ui->textEditCode->toPlainText();
  qDebug() << _codeTheme;
  emit  setCodeTheme(_codeTheme);
}

void  DialTestThemeCode::getCode(QString code)
{
  setWindowTitle("Show current code theme");
  this->ui->textEditCode->clear();
  this->ui->textEditCode->setText(code);
  _codeTheme = code;
  emit  setCodeTheme(_codeTheme);
}
