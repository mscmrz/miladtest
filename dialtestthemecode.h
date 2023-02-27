#ifndef DIALTESTTHEMECODE_H
#define DIALTESTTHEMECODE_H

#include <QDialog>

namespace Ui
{
class DialTestThemeCode;
}

class DialTestThemeCode: public QDialog
{
  Q_OBJECT

signals:
  void  setCodeTheme(QString codeTheme);

public:
  explicit DialTestThemeCode(QWidget *parent = nullptr);

  ~DialTestThemeCode();

public slots:
  void  getCode(QString code);

private slots:
  void  on_btn_Ok_clicked();

  void  on_btn_Apply_clicked();

private:
  Ui::DialTestThemeCode *ui;
  QString                _codeTheme;
};

#endif // DIALTESTTHEMECODE_H
