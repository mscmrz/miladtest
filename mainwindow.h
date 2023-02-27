#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include "dialtestthemecode.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

signals:
  void     sendCodeTheme(QString code);

private slots:
  void     on_btn_setTheme_clicked();

  void     on_btn_PushButtonColor_clicked();

  void     on_btn_GroupBoxColor_clicked();

  void     on_btn_RadioButtonColor_clicked();

  void     on_btn_LineEditColor_clicked();

  void     on_btn_TextlableColor_clicked();

  void     on_btn_CheckBoxColor_clicked();

  void     on_btn_spinBoxColor_clicked();

  void     on_btn_doubleSpinBoxColor_clicked();

  void     on_btn_comboBoxColor_clicked();

  void     on_btn_treeWidgetColor_clicked();

  void     on_btn_widgetColor_clicked();

  void     on_btn_tableViewColor_clicked();

  void     on_btn_tabWidgetColor_clicked();

  void     on_btn_LineEditFont_clicked();

  void     on_btn_PushButtonFont_clicked();

  void     on_btn_RadioButtonFont_clicked();

  void     on_btn_CheckBoxFont_clicked();

  void     on_btn_GroupBoxFont_clicked();

  void     on_btn_tabWidgetFont_clicked();

  void     on_btn_TextlableFont_clicked();

  void     on_btn_spinBoxFont_clicked();

  void     on_btn_doubleSpinBoxFont_clicked();

  void     on_btn_comboBoxFont_clicked();

  void     on_btn_widgetFont_clicked();

  void     on_btn_treeWidgetFont_clicked();

  void     on_btn_tableViewFont_clicked();

  void     on_btn_ThemeDefault_clicked();

  void     on_btn_PushButtonGradient_clicked();

  void     on_btn_RadioButtonGradient_clicked();

  void     on_btn_CheckBoxGradient_clicked();

  void     on_btn_GroupBoxGradient_clicked();

  void     on_btn_TextlableGradient_clicked();

  void     on_btn_LineEditGradient_clicked();

  void     on_btn_spinBoxGradient_clicked();

  void     on_btn_doubleSpinBoxGradient_clicked();

  void     on_btn_widgetGradient_clicked();

  void     on_btn_treeWidgetGradient_clicked();

  void     on_btn_tableViewGradient_clicked();

  void     on_btn_saveTheme_clicked();

  void     on_btn_treeViewColor_clicked();

  void     on_btn_treeViewGradient_clicked();

  void     on_btn_treeViewFont_clicked();

  void     on_btn_loadTheme_clicked();

  void     on_btn_PushButtonFontColor_clicked();

  void     on_btn_RadioButtonFontColor_clicked();

  void     on_btn_CheckBoxFontColor_clicked();

  void     on_btn_GroupBoxFontColor_clicked();

  void     on_btn_tabWidgetFontColor_clicked();

  void     on_btn_TextlableFontColor_clicked();

  void     on_btn_LineEditFontColor_clicked();

  void     on_btn_spinBoxFontColor_clicked();

  void     on_btn_doubleSpinBoxFontColor_clicked();

  void     on_btn_comboBoxFontColor_clicked();

  void     on_btn_widgetFontColor_clicked();

  void     on_btn_treeWidgetFontColor_clicked();

  void     on_btn_tableViewFontColor_clicked();

  void     on_btn_treeViewFontColor_clicked();

  void     on_btn_testThemeCode_clicked();

  void     updateThemeColor();

  void     updateThemeFont();

  void     updateThemeFontColor();

  void     themeDefualt();

  void     setUpdateTheme();

  void     on_btn_ShowCurrentCode_clicked();

  QString  valueFontStyle(int type);

  QString  setColorGradient(QColor color);

  QString  valueFontWeight(int weight);

  QString  setAllFont(QFont type);

  bool     setValueColor();

  void     updateCurrentCode(QString value);

private:
  Ui::MainWindow    *ui;
  DialTestThemeCode *testTheme;
  DialTestThemeCode *showTheme;
  QFile             *file;
  QString            _ThemeString;
  QString            _themStringColor;
  QString            _themStringFont;
  QString            _themStringFontColor;
  QString            _colorString1;
  QString            _colorString2;
  QString            _qwidget;
  QString            _qlineEdit;
  QString            _qradioButton;
  QString            _qcheckBox;
  QString            _qlabel;
  QString            _qgroupBox;
  QString            _qspinBox;
  QString            _qpushButton;
  QString            _qtreeView;
  QString            _qtableView;
  QString            _qdoubleSpinBox;
  QString            _qcomboBox;
  QString            _qtabWidget;
  QString            _qtreeWidget;
  QString            _qwidgetFontString;
  QString            _qlineEditFontString;
  QString            _qradioButtonFontString;
  QString            _qcheckBoxFontString;
  QString            _qlabelFontString;
  QString            _qgroupBoxFontString;
  QString            _qspinBoxFontString;
  QString            _qpushButtonFontString;
  QString            _qtreeViewFontString;
  QString            _qtableViewFontString;
  QString            _qdoubleSpinBoxFontString;
  QString            _qcomboBoxFontString;
  QString            _qtabWidgetFontString;
  QString            _qtreeWidgetFontString;
  QString            _qwidgetFontColorString;
  QString            _qlineEditFontColorString;
  QString            _qradioButtonFontColorString;
  QString            _qcheckBoxFontColorString;
  QString            _qlabelFontColorString;
  QString            _qgroupBoxFontColorString;
  QString            _qspinBoxFontColorString;
  QString            _qpushButtonFontColorString;
  QString            _qtreeViewFontColorString;
  QString            _qtableViewFontColorString;
  QString            _qdoubleSpinBoxFontColorString;
  QString            _qcomboBoxFontColorString;
  QString            _qtabWidgetFontColorString;
  QString            _qtreeWidgetFontColorString;
  int                _maxSizeFont = 20;
  int                _minSizeFont = 6;
};


#endif // MAINWINDOW_H
