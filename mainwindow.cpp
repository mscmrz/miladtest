#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialtestthemecode.h"
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QDebug>
#include <QTableView>
#include <QShortcut>
#include <QPainter>
#include <QColor>
#include <QFile>
#include <QMessageBox>
#include <QDir>

MainWindow::MainWindow(QWidget *parent):
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  testTheme = new DialTestThemeCode();
  showTheme = new DialTestThemeCode();

  auto  runThemeKey      = new QShortcut(QKeySequence(tr("CTRL+r")), this);
  auto  loadThemeKey     = new QShortcut(QKeySequence(tr("CTRL+o")), this);
  auto  testThemeKey     = new QShortcut(QKeySequence(tr("CTRL+t")), this);
  auto  saveThemeKey     = new QShortcut(QKeySequence(tr("CTRL+s")), this);
  auto  showCodeThemeKey = new QShortcut(QKeySequence(tr("CTRL+W")), this);


  connect(runThemeKey, &QShortcut::activated, this, &MainWindow::on_btn_setTheme_clicked);
  connect(loadThemeKey, &QShortcut::activated, this, &MainWindow::on_btn_loadTheme_clicked);
  connect(testThemeKey, &QShortcut::activated, this, &MainWindow::on_btn_testThemeCode_clicked);
  connect(saveThemeKey, &QShortcut::activated, this, &MainWindow::on_btn_saveTheme_clicked);
  connect(showCodeThemeKey, &QShortcut::activated, this, &MainWindow::on_btn_ShowCurrentCode_clicked);
  connect(this, &MainWindow::sendCodeTheme, showTheme, &DialTestThemeCode::getCode);


  connect(testTheme, &DialTestThemeCode::setCodeTheme, [ = ](QString str)
  {
    setStyleSheet(str);
  });

  connect(showTheme, &DialTestThemeCode::setCodeTheme, [ = ](QString str)
  {
// updateCurrentCode(str);
    _ThemeString = str;
    setStyleSheet(_ThemeString);
  });

  themeDefualt();
}

MainWindow::~MainWindow()
{
  delete ui;
}

// color
void  MainWindow::on_btn_PushButtonColor_clicked()
{
  bool    ok;
  QColor  btn_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qpushButtonName = btn_Color.name();
  this->ui->pushButton->setStyleSheet("background-color:" + qpushButtonName);
  qDebug() << "Color Choosen : " << qpushButtonName;
  _qpushButton = QString("QPushButton{background-color:%1;}").arg(qpushButtonName);
  updateThemeColor();
}

void  MainWindow::on_btn_GroupBoxColor_clicked()
{
  bool    ok;
  QColor  grpbox_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qgroupBoxName = grpbox_Color.name();
  this->ui->groupBox->setStyleSheet("background-color:" + qgroupBoxName);
  qDebug() << "Color Choosen : " << qgroupBoxName;
  _qgroupBox = QString("QGroupBox{background-color:%1;}").arg(qgroupBoxName);
  updateThemeColor();
}

void  MainWindow::on_btn_RadioButtonColor_clicked()
{
  bool    ok;
  QColor  radioButton_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qradioButtonName = radioButton_Color.name();
  this->ui->radioButton->setStyleSheet("background-color:" + qradioButtonName);
  qDebug() << "Color Choosen : " << qradioButtonName;
  _qradioButton = QString("QRadioButton{background-color:%1;}").arg(qradioButtonName);
  updateThemeColor();
}

void  MainWindow::on_btn_LineEditColor_clicked()
{
  bool    ok;
  QColor  lineEdit_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qlineEditName = lineEdit_Color.name();
  this->ui->lineEdit->setStyleSheet("background-color:" + qlineEditName);
  qDebug() << "Color Choosen : " << qlineEditName;
  _qlineEdit = QString("QLineEdit{background-color:%1;}").arg(qlineEditName);
  updateThemeColor();
}

void  MainWindow::on_btn_TextlableColor_clicked()
{
  bool    ok;
  QColor  textlabel_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  _labelName = textlabel_Color.name();
  this->ui->label->setStyleSheet("background-color:" + _labelName);
  qDebug() << "Color Choosen : " << _qlabel;
  _qlabel = QString("QLabel{background-color:%1;}").arg(_labelName);
  updateThemeColor();
}

void  MainWindow::on_btn_CheckBoxColor_clicked()
{
  bool    ok;
  QColor  checkBox_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qcheckBoxName = checkBox_Color.name();
  this->ui->checkBox->setStyleSheet("background-color:" + qcheckBoxName);
  qDebug() << "Color Choosen : " << qcheckBoxName;
  _qcheckBox = QString("QCheckBox{background-color:%1;}").arg(qcheckBoxName);
  updateThemeColor();
}

void  MainWindow::on_btn_spinBoxColor_clicked()
{
  bool    ok;
  QColor  spinBox_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qspinBoxName = spinBox_Color.name();
  this->ui->spinBox->setStyleSheet("background-color:" + qspinBoxName);
  qDebug() << "Color Choosen : " << qspinBoxName;
  _qspinBox = QString("QSpinBox{background-color:%1;}").arg(qspinBoxName);
  updateThemeColor();
}

void  MainWindow::on_btn_doubleSpinBoxColor_clicked()
{
  bool    ok;
  QColor  doubleSpinBox_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qdoubleSpinBoxName = doubleSpinBox_Color.name();
  this->ui->doubleSpinBox->setStyleSheet("background-color:" + qdoubleSpinBoxName);
  qDebug() << "Color Choosen : " << qdoubleSpinBoxName;
  _qdoubleSpinBox = QString("QDoubleSpinBox{background-color:%1;}").arg(qdoubleSpinBoxName);
  updateThemeColor();
}

void  MainWindow::on_btn_comboBoxColor_clicked()
{
  bool    ok;
  QColor  comboBox_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  _qcomboBox = "";
  QString  qcomboBoxName = comboBox_Color.name();
  this->ui->comboBox->setStyleSheet("background-color:" + qcomboBoxName);
  qDebug() << "Color Choosen : " << qcomboBoxName;
  _qcomboBox = QString("QComboBox{background-color:%1;}").arg(qcomboBoxName);
  updateThemeColor();
}

void  MainWindow::on_btn_treeWidgetColor_clicked()
{
  bool    ok;
  QColor  treeWidget_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qtreeWidgetName = treeWidget_Color.name();
  this->ui->treeWidget->setStyleSheet("background-color:" + qtreeWidgetName);
  qDebug() << "Color Choosen : " << qtreeWidgetName;
  _qtreeWidget = QString("QTreeWidget{background-color:%1;}").arg(qtreeWidgetName);
  updateThemeColor();
}

void  MainWindow::on_btn_widgetColor_clicked()
{
  bool    ok;
  QColor  widget_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qwidgetName = widget_Color.name();
  this->ui->widget->setStyleSheet("background-color:" + qwidgetName);
  qDebug() << "Color Choosen : " << qwidgetName;
  _qwidget = QString("QWidget{background-color:%1;}").arg(qwidgetName);
  updateThemeColor();
}

void  MainWindow::on_btn_tableViewColor_clicked()
{
  bool    ok;
  QColor  tableView_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qtableViewName = tableView_Color.name();
  this->ui->tableView->setStyleSheet("background-color:" + qtableViewName);
  qDebug() << "Color Choosen : " << qtableViewName;
  _qtableView = QString("QTableView{background-color:%1;}").arg(qtableViewName);
  updateThemeColor();
}

void  MainWindow::on_btn_tabWidgetColor_clicked()
{
  bool    ok;
  QColor  tabWidget_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qtabWidgetName = tabWidget_Color.name();
  this->ui->tabWidget->setStyleSheet("background-color:" + qtabWidgetName);
  qDebug() << "Color Choosen : " << qtabWidgetName;
  _qtabWidget = QString("QTabWidget{background-color:%1;} QTabBar:tab{background-color:%1;}").arg(qtabWidgetName);
  updateThemeColor();
}

void  MainWindow::on_btn_treeViewColor_clicked()
{
  bool    ok;
  QColor  treeView_Color = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qtreeViewName = treeView_Color.name();
  this->ui->treeView->setStyleSheet("background-color:" + qtreeViewName);
  qDebug() << "Color Choosen : " << qtreeViewName;
  _qtreeView = QString("QTreeView{background-color:%1;}").arg(qtreeViewName);
  updateThemeColor();
}

// Gradient

void  MainWindow::on_btn_PushButtonGradient_clicked()
{
  if (setValueColor())
  {
    _qpushButton.clear();
    _qpushButton = QString("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->pushButton->setStyleSheet(_qpushButton);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_RadioButtonGradient_clicked()
{
  if (setValueColor())
  {
    _qradioButton.clear();
    _qradioButton = QString("QRadioButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->radioButton->setStyleSheet(_qradioButton);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_CheckBoxGradient_clicked()
{
  if (setValueColor())
  {
    _qcheckBox.clear();
    _qcheckBox = QString("QCheckBox{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->checkBox->setStyleSheet(_qcheckBox);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_GroupBoxGradient_clicked()
{
  if (setValueColor())
  {
    _qgroupBox.clear();
    _qgroupBox = QString("QGroupBox{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->groupBox->setStyleSheet(_qgroupBox);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_TextlableGradient_clicked()
{
  if (setValueColor())
  {
    _qlabel.clear();
    _qlabel = QString("QLabel{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->label->setStyleSheet(_qlabel);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_LineEditGradient_clicked()
{
  if (setValueColor())
  {
    _qlineEdit.clear();
    _qlineEdit = QString("QLineEdit{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->lineEdit->setStyleSheet(_qlineEdit);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_spinBoxGradient_clicked()
{
  if (setValueColor())
  {
    _qspinBox.clear();
    _qspinBox = QString("QSpinBox{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->spinBox->setStyleSheet(_qspinBox);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_doubleSpinBoxGradient_clicked()
{
  if (setValueColor())
  {
    _qdoubleSpinBox.clear();
    _qdoubleSpinBox = QString("QDoubleSpinBox{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->doubleSpinBox->setStyleSheet(_qdoubleSpinBox);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_widgetGradient_clicked()
{
  if (setValueColor())
  {
    _qwidget.clear();
    _qwidget = QString("QWidget{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->widget->setStyleSheet(_qwidget);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_treeWidgetGradient_clicked()
{
  if (setValueColor())
  {
    _qtreeWidget.clear();
    _qtreeWidget = QString("QTreeWidget{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->treeWidget->setStyleSheet(_qtreeWidget);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_tableViewGradient_clicked()
{
  if (setValueColor())
  {
    _qtableView.clear();
    _qtableView = QString("QTableView{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->tableView->setStyleSheet(_qtableView);
    updateThemeColor();
  }
}

void  MainWindow::on_btn_treeViewGradient_clicked()
{
  if (setValueColor())
  {
    _qtreeView.clear();
    _qtreeView = QString("QTreeView{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(%1), stop:1 rgba(%2));}").arg(
      _colorString1).arg(_colorString2);
    this->ui->treeView->setStyleSheet(_qtreeView);
    updateThemeColor();
  }
}

// Fonts

void  MainWindow::on_btn_LineEditFont_clicked()
{
  bool   ok;
  QFont  lineEditFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((lineEditFont.pointSize() < _minSizeFont) || (lineEditFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qlineEditFontString = "";
    _qlineEditFontString = "QLineEdit" + setAllFont(lineEditFont);

    this->ui->lineEdit->setFont(lineEditFont);

    qDebug() << _qlineEditFontString;

    updateThemeFont();
  }

// bool         ok;
// QFontDialog *fontDial = new QFontDialog;

// fontDial->setMaximumSize(10, 20);
// fontDial->setMinimumSize(10, 20);
// QFont  lineEditFont = fontDial->getFont(&ok);

// if (ok)
// {
// if ((lineEditFont.pointSize() < _minSizeFont) || (lineEditFont.pointSize() > _maxSizeFont))
// {
// return;
// }

// _qlineEditFontString = "";
// _qlineEditFontString = "QLineEdit" + setAllFont(lineEditFont);

// this->ui->lineEdit->setFont(lineEditFont);

// qDebug() << _qlineEditFontString;

// updateThemeFont();
// }
}

void  MainWindow::on_btn_PushButtonFont_clicked()
{
  bool   ok;
  QFont  pushButtonFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((pushButtonFont.pointSize() < _minSizeFont) || (pushButtonFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qpushButtonFontString = "";

    _qpushButtonFontString = "QPushButton" + setAllFont(pushButtonFont);

    this->ui->pushButton->setFont(pushButtonFont);

    qDebug() << _qpushButtonFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_RadioButtonFont_clicked()
{
  bool   ok;
  QFont  radioButtonFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((radioButtonFont.pointSize() < _minSizeFont) || (radioButtonFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qradioButtonFontString.clear();
    _qradioButtonFontString = "QRadioButton" + setAllFont(radioButtonFont);

    this->ui->radioButton->setFont(radioButtonFont);

    qDebug() << _qradioButtonFontString;
    updateThemeFont();
  }
}

void  MainWindow::on_btn_CheckBoxFont_clicked()
{
  bool   ok;
  QFont  checkBoxFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((checkBoxFont.pointSize() < _minSizeFont) || (checkBoxFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qcheckBoxFontString = "";
    _qcheckBoxFontString = "QCheckBox" + setAllFont(checkBoxFont);

    this->ui->checkBox->setFont(checkBoxFont);

    qDebug() << _qcheckBoxFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_GroupBoxFont_clicked()
{
  bool   ok;
  QFont  groupBoxFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((groupBoxFont.pointSize() < _minSizeFont) || (groupBoxFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qgroupBoxFontString = "";

    _qgroupBoxFontString = "QGroupBox" + setAllFont(groupBoxFont);

    this->ui->groupBox->setFont(groupBoxFont);

    qDebug() << _qgroupBoxFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_tabWidgetFont_clicked()
{
  bool   ok;
  QFont  abWidgetFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((abWidgetFont.pointSize() < _minSizeFont) || (abWidgetFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qtabWidgetFontString = "";

    _qtabWidgetFontString = "QTabWidget" + setAllFont(abWidgetFont);

    this->ui->tabWidget->setFont(abWidgetFont);

    qDebug() << _qtabWidgetFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_TextlableFont_clicked()
{
  bool   ok;
  QFont  labelFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((labelFont.pointSize() < _minSizeFont) || (labelFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qlabelFontString = "";

    _qlabelFontString = "QLabel" + setAllFont(labelFont);

    this->ui->label->setFont(labelFont);

    qDebug() << _qlabelFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_spinBoxFont_clicked()
{
  bool   ok;
  QFont  spinBoxFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((spinBoxFont.pointSize() < _minSizeFont) || (spinBoxFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qspinBoxFontString = "";

    _qspinBoxFontString = "QSpinBox" + setAllFont(spinBoxFont);

    this->ui->spinBox->setFont(spinBoxFont);

    qDebug() << _qspinBoxFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_doubleSpinBoxFont_clicked()
{
  bool   ok;
  QFont  doubleSpinBoxFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((doubleSpinBoxFont.pointSize() < _minSizeFont) || (doubleSpinBoxFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qdoubleSpinBoxFontString = "";

    _qdoubleSpinBoxFontString = "QDoubleSpinBox" + setAllFont(doubleSpinBoxFont);

    this->ui->doubleSpinBox->setFont(doubleSpinBoxFont);

    qDebug() << _qdoubleSpinBoxFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_comboBoxFont_clicked()
{
  bool   ok;
  QFont  comboBoxFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((comboBoxFont.pointSize() < _minSizeFont) || (comboBoxFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qcomboBoxFontString = "";

    _qcomboBoxFontString = "QComboBox" + setAllFont(comboBoxFont);

    this->ui->comboBox->setFont(comboBoxFont);

    qDebug() << _qcomboBoxFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_widgetFont_clicked()
{
  bool   ok;
  QFont  widgetFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((widgetFont.pointSize() < _minSizeFont) || (widgetFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qwidgetFontString = "";

    _qwidgetFontString = "QWidget" + setAllFont(widgetFont);

    this->ui->widget->setFont(widgetFont);

    qDebug() << _qwidgetFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_treeWidgetFont_clicked()
{
  bool   ok;
  QFont  treeWidgetFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((treeWidgetFont.pointSize() < _minSizeFont) || (treeWidgetFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qtreeWidgetFontString = "";

    _qtreeWidgetFontString = "QTreeView" + setAllFont(treeWidgetFont);

    this->ui->treeWidget->setFont(treeWidgetFont);

    qDebug() << _qtreeWidgetFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_tableViewFont_clicked()
{
  bool   ok;
  QFont  tableViewFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((tableViewFont.pointSize() < _minSizeFont) || (tableViewFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qtableViewFontString = "";

    _qtableViewFontString = "QTableView" + setAllFont(tableViewFont);

    this->ui->tableView->setFont(tableViewFont);

    qDebug() << _qtableViewFontString;

    updateThemeFont();
  }
}

void  MainWindow::on_btn_treeViewFont_clicked()
{
  bool   ok;
  QFont  treeViewFont = QFontDialog::getFont(&ok);

  if (ok)
  {
    if ((treeViewFont.pointSize() < _minSizeFont) || (treeViewFont.pointSize() > _maxSizeFont))
    {
      return;
    }

    _qtreeViewFontString = "";

    _qtreeViewFontString = "QTreeView" + setAllFont(treeViewFont);

    this->ui->treeView->setFont(treeViewFont);

    qDebug() << _qtreeViewFontString;

    updateThemeFont();
  }
}

// Font color
void  MainWindow::on_btn_PushButtonFontColor_clicked()
{
  bool    ok;
  QColor  btn_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  qpushButtonName = btn_FontColor.name();
  this->ui->pushButton->setStyleSheet("color:" + qpushButtonName);
  qDebug() << "Color Choosen : " << qpushButtonName;
  _qpushButtonFontColorString = QString("QPushButton{color:%1;}").arg(qpushButtonName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_RadioButtonFontColor_clicked()
{
  bool    ok;
  QColor  radio_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  radioButtonName = radio_FontColor.name();
  this->ui->radioButton->setStyleSheet("color:" + radioButtonName);
  qDebug() << "Color Choosen : " << radioButtonName;
  _qradioButtonFontColorString = QString("QRadioButton{color:%1;}").arg(radioButtonName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_CheckBoxFontColor_clicked()
{
  bool    ok;
  QColor  CheckBox_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  CheckBoxName = CheckBox_FontColor.name();
  this->ui->checkBox->setStyleSheet("color:" + CheckBoxName);
  qDebug() << "Color Choosen : " << CheckBoxName;
  _qcheckBoxFontColorString = QString("QCheckBox{color:%1;}").arg(CheckBoxName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_GroupBoxFontColor_clicked()
{
  bool    ok;
  QColor  GroupBox_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  GroupBoxName = GroupBox_FontColor.name();
  this->ui->groupBox->setStyleSheet("color:" + GroupBoxName);
  qDebug() << "Color Choosen : " << GroupBoxName;
  _qgroupBoxFontColorString = QString("QGroupBox{color:%1;}").arg(GroupBoxName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_tabWidgetFontColor_clicked()
{
  bool    ok;
  QColor  tabWidget_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  tabWidgetName = tabWidget_FontColor.name();
  this->ui->tabWidget->setStyleSheet("color:" + tabWidgetName);
  qDebug() << "Color Choosen : " << tabWidgetName;
  _qtabWidgetFontColorString = QString("QTabBar:tab{color:%1;}").arg(tabWidgetName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_TextlableFontColor_clicked()
{
  bool    ok;
  QColor  lable_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  lableName = lable_FontColor.name();
  this->ui->label->setStyleSheet("color:" + lableName);
  qDebug() << "Color Choosen : " << lableName;
  _qlabelFontColorString = QString("QLabel{color:%1;}").arg(lableName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_LineEditFontColor_clicked()
{
  bool    ok;
  QColor  LineEdit_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  lineEditName = LineEdit_FontColor.name();
  this->ui->lineEdit->setStyleSheet("color:" + lineEditName);
  qDebug() << "Color Choosen : " << lineEditName;
  _qlineEditFontColorString = QString("QLineEdit{color:%1;}").arg(lineEditName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_spinBoxFontColor_clicked()
{
  bool    ok;
  QColor  spinBoxF_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  spinBoxFName = spinBoxF_FontColor.name();
  this->ui->spinBox->setStyleSheet("color:" + spinBoxFName);
  qDebug() << "Color Choosen : " << spinBoxFName;
  _qspinBoxFontColorString = QString("QSpinBox{color:%1;}").arg(spinBoxFName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_doubleSpinBoxFontColor_clicked()
{
  bool    ok;
  QColor  doubleSpinBox_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  doubleSpinBoxName = doubleSpinBox_FontColor.name();
  this->ui->doubleSpinBox->setStyleSheet("color:" + doubleSpinBoxName);
  qDebug() << "Color Choosen : " << doubleSpinBoxName;
  _qdoubleSpinBoxFontColorString = QString("QDoubleSpinBox{color:%1;}").arg(doubleSpinBoxName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_comboBoxFontColor_clicked()
{
  bool    ok;
  QColor  comboBox_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  comboBoxName = comboBox_FontColor.name();
  this->ui->comboBox->setStyleSheet("color:" + comboBoxName);
  qDebug() << "Color Choosen : " << comboBoxName;
  _qcomboBoxFontColorString = QString("QComboBox{color:%1;}").arg(comboBoxName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_widgetFontColor_clicked()
{
  bool    ok;
  QColor  widget_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  widgetName = widget_FontColor.name();
  this->ui->widget->setStyleSheet("color:" + widgetName);
  qDebug() << "Color Choosen : " << widgetName;
  _qwidgetFontColorString = QString("QWidget{color:%1;}").arg(widgetName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_treeWidgetFontColor_clicked()
{
  bool    ok;
  QColor  treeWidget_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  treeWidgetName = treeWidget_FontColor.name();
  this->ui->treeWidget->setStyleSheet("color:" + treeWidgetName);
  qDebug() << "Color Choosen : " << treeWidgetName;
  _qtreeWidgetFontColorString = QString("QTreeWidget:headerItem{color:%1;}").arg(treeWidgetName);
  qDebug() << _qtreeWidgetFontColorString;
  updateThemeFontColor();
}

void  MainWindow::on_btn_tableViewFontColor_clicked()
{
  bool    ok;
  QColor  tableView_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  tableViewName = tableView_FontColor.name();
  this->ui->tableView->setStyleSheet("color:" + tableViewName);
  qDebug() << "Color Choosen : " << tableViewName;
  _qtableViewFontColorString = QString("QTableView{color:%1;}").arg(tableViewName);
  updateThemeFontColor();
}

void  MainWindow::on_btn_treeViewFontColor_clicked()
{
  bool    ok;
  QColor  treeView_FontColor = QColorDialog::getRgba(0xffffffff, &ok);

  if (!ok)
  {
    return;
  }

  QString  treeViewName = treeView_FontColor.name();
  this->ui->treeView->setStyleSheet("color:" + treeViewName);
  qDebug() << "Color Choosen : " << treeViewName;
  _qtreeViewFontColorString = QString("QTreeView{color:%1;}").arg(treeViewName);
  updateThemeFontColor();
}

// set default theme

void  MainWindow::on_btn_ThemeDefault_clicked()
{
  // color
// _qwidget        = "QWidget{background-color:;}";
// _qlineEdit      = "QLineEdit{background-color:;}";
// _qradioButton   = "QRadioButton{background-color:;}";
// _qcheckBox      = "QCheckBox{background-color:;}";
// _qlabel         = "QLabel{background-color:;}";
// _qgroupBox      = "QGroupBox{background-color:;}";
// _qspinBox       = "QSpinBox{background-color:;}";
// _qpushButton    = "QPushButton{background-color:;}";
// _qtreeView      = "QTreeView{background-color:;}";
// _qtableView     = "QTableView{background-color:;}";
// _qdoubleSpinBox = "QDoubleSpinBox{background-color:;}";
// _qcomboBox      = "QComboBox{background-color:;}";
// _qtabWidget     = "QTabWidget{background-color:;}";
// _qtreeWidget    = "QTreeWidget{background-color:;}";
//// font
// _qwidgetFontString        = "QWidget{font:;}";
// _qlineEditFontString      = "QLineEdit{font:;}";
// _qradioButtonFontString   = "QRadioButton{font:;}";
// _qcheckBoxFontString      = "QCheckBox{font:;}";
// _qlabelFontString         = "QLabel{font:;}";
// _qgroupBoxFontString      = "QGroupBox{font:;}";
// _qspinBoxFontString       = "QSpinBox{font:;}";
// _qpushButtonFontString    = "QPushButton{font:;}";
// _qtreeViewFontString      = "QTreeView{font:;}";
// _qtableViewFontString     = "QTableView{font:;}";
// _qdoubleSpinBoxFontString = "QDoubleSpinBox{font:;}";
// _qcomboBoxFontString      = "QComboBox{font:;}";
// _qtabWidgetFontString     = "QTabWidget{font:;}";
// _qtreeWidgetFontString    = "QTreeWidget{font:;}";

// this->setStyleSheet("font: 50 8pt MS Shell Dlg 2");
}

// Update color and gradient
void  MainWindow::updateThemeColor()
{
  _themStringColor.clear();
  _themStringColor = QString("%1\n"
                             "%2\n"
                             "%3\n"
                             "%4\n"
                             "%5\n"
                             "%6\n"
                             "%7\n"
                             "%8\n"
                             "%9\n"
                             "%10\n"
                             "%11\n"
                             "%12\n"
                             "%13\n"
                             "%14\n"
                             ).arg(_qwidget).arg(_qlineEdit).arg(_qradioButton).arg(_qcheckBox).arg(_qlabel).arg(_qgroupBox).arg(_qspinBox).arg(_qpushButton).
                     arg(_qtreeView).arg(_qtableView).arg(_qdoubleSpinBox).arg(_qcomboBox).arg(_qtabWidget).arg(_qtreeWidget);
  setUpdateTheme();
}

// Update Font

void  MainWindow::updateThemeFont()
{
  _themStringFont.clear();
  _themStringFont = QString("%1\n"
                            "%2\n"
                            "%3\n"
                            "%4\n"
                            "%5\n"
                            "%6\n"
                            "%7\n"
                            "%8\n"
                            "%9\n"
                            "%10\n"
                            "%11\n"
                            "%12\n"
                            "%13\n"
                            "%14\n"
                            ).arg(_qwidgetFontString).arg(_qlineEditFontString).arg(_qradioButtonFontString).arg(_qcheckBoxFontString).arg(_qlabelFontString).
                    arg(_qgroupBoxFontString).arg(_qspinBoxFontString).arg(_qpushButtonFontString).arg(_qtreeViewFontString).arg(_qtableViewFontString).arg(
    _qdoubleSpinBoxFontString).arg(_qcomboBoxFontString).arg(_qtabWidgetFontString).arg(_qtreeWidgetFontString);
  setUpdateTheme();
}

// Update Font Color

void  MainWindow::updateThemeFontColor()
{
  _themStringFontColor.clear();
  _themStringFontColor = QString("%1\n"
                                 "%2\n"
                                 "%3\n"
                                 "%4\n"
                                 "%5\n"
                                 "%6\n"
                                 "%7\n"
                                 "%8\n"
                                 "%9\n"
                                 "%10\n"
                                 "%11\n"
                                 "%12\n"
                                 "%13\n"
                                 "%14\n"
                                 ).arg(_qwidgetFontColorString).arg(_qlineEditFontColorString).arg(_qradioButtonFontColorString).arg(_qcheckBoxFontColorString).
                         arg(_qlabelFontColorString).arg(_qgroupBoxFontColorString).arg(_qspinBoxFontColorString).arg(_qpushButtonFontColorString).
                         arg(_qtreeViewFontColorString).arg(_qtableViewFontColorString).arg(_qdoubleSpinBoxFontColorString).arg(_qcomboBoxFontColorString).arg(
    _qtabWidgetFontColorString).arg(_qtreeWidgetFontColorString);
// qDebug() << _themStringFontColor;
  setUpdateTheme();
}

// save custome theme to file

void  MainWindow::on_btn_saveTheme_clicked()
{
  QString  strFileName = QDir().currentPath() + "/customTheme.txt";

  qDebug() << strFileName;

  file = new QFile(strFileName);

  if (_ThemeString != nullptr)
  {
    int  ret = QMessageBox::question(this, tr("Save File"),
                                     tr("The document has been modified."
                                        "Do you want to save your changes?"),
                                     QMessageBox::Save | QMessageBox::Cancel,
                                     QMessageBox::Save);

    switch (ret)
    {
    case QMessageBox::Save:
    {
      if ((file->open(QIODevice::WriteOnly | QIODevice::Text)))
      {
        file->open(QIODevice::WriteOnly | QIODevice::Text);

        QTextStream  out(file);

        out << _ThemeString;
        file->close();
      }

      break;
    }
    case QMessageBox::Cancel:
    {
      break;
    }
    }
  }
}

// Load theme
void  MainWindow::on_btn_loadTheme_clicked()
{
  QString      fileName = QFileDialog::getOpenFileName(this, tr("Opne Theme File"), tr("*.txt"));
  QFile        themeFile(fileName);
  QStringList  list;
  QString      textFile;
  QRegExp      rx("[:a-zA-Z0-9 .]*[;]");

  if (themeFile.open(QIODevice::ReadWrite | QIODevice::Text))
  {
    textFile = themeFile.readAll();
    _ThemeString.clear();
    _ThemeString = textFile;

    list                           = textFile.split('\n');
    _qwidget                       = list[0];
    _qlineEdit                     = list[1];
    _qradioButton                  = list[2];
    _qcheckBox                     = list[3];
    _qlabel                        = list[4];
    _qgroupBox                     = list[5];
    _qspinBox                      = list[6];
    _qpushButton                   = list[7];
    _qtreeView                     = list[8];
    _qtableView                    = list[9];
    _qdoubleSpinBox                = list[10];
    _qcomboBox                     = list[11];
    _qtabWidget                    = list[12];
    _qtreeWidget                   = list[13];
    _qwidgetFontString             = list[14];
    _qlineEditFontString           = list[15];
    _qradioButtonFontString        = list[16];
    _qcheckBoxFontString           = list[17];
    _qlabelFontString              = list[18];
    _qgroupBoxFontString           = list[19];
    _qspinBoxFontString            = list[20];
    _qpushButtonFontString         = list[21];
    _qtreeViewFontString           = list[22];
    _qtableViewFontString          = list[23];
    _qdoubleSpinBoxFontString      = list[24];
    _qcomboBoxFontString           = list[25];
    _qtabWidgetFontString          = list[26];
    _qtreeWidgetFontString         = list[27];
    _qwidgetFontColorString        = list[28];
    _qlineEditFontColorString      = list[29];
    _qradioButtonFontColorString   = list[30];
    _qcheckBoxFontColorString      = list[31];
    _qlabelFontColorString         = list[32];
    _qgroupBoxFontColorString      = list[33];
    _qspinBoxFontColorString       = list[34];
    _qpushButtonFontColorString    = list[35];
    _qtreeViewFontColorString      = list[36];
    _qtableViewFontColorString     = list[37];
    _qdoubleSpinBoxFontColorString = list[38];
    _qcomboBoxFontColorString      = list[39];
    _qtabWidgetFontColorString     = list[40];
    _qtreeWidgetFontColorString    = list[41];

    updateThemeColor();
    updateThemeFont();
    updateThemeFontColor();
    this->setStyleSheet(_ThemeString);
    themeFile.close();
  }
}

void  MainWindow::updateCurrentCode(QString value)
{
// QStringList  list;

// list                           = value.split('\n');
// _qwidget                       = list[0];
// _qlineEdit                     = list[1];
// _qradioButton                  = list[2];
// _qcheckBox                     = list[3];
// _qlabel                        = list[4];
// _qgroupBox                     = list[5];
// _qspinBox                      = list[6];
// _qpushButton                   = list[7];
// _qtreeView                     = list[8];
// _qtableView                    = list[9];
// _qdoubleSpinBox                = list[10];
// _qcomboBox                     = list[11];
// _qtabWidget                    = list[12];
// _qtreeWidget                   = list[13];
// _qwidgetFontString             = list[14];
// _qlineEditFontString           = list[15];
// _qradioButtonFontString        = list[16];
// _qcheckBoxFontString           = list[17];
// _qlabelFontString              = list[18];
// _qgroupBoxFontString           = list[19];
// _qspinBoxFontString            = list[20];
// _qpushButtonFontString         = list[21];
// _qtreeViewFontString           = list[22];
// _qtableViewFontString          = list[23];
// _qdoubleSpinBoxFontString      = list[24];
// _qcomboBoxFontString           = list[25];
// _qtabWidgetFontString          = list[26];
// _qtreeWidgetFontString         = list[27];
// _qwidgetFontColorString        = list[28];
// _qlineEditFontColorString      = list[29];
// _qradioButtonFontColorString   = list[30];
// _qcheckBoxFontColorString      = list[31];
// _qlabelFontColorString         = list[32];
// _qgroupBoxFontColorString      = list[33];
// _qspinBoxFontColorString       = list[34];
// _qpushButtonFontColorString    = list[35];
// _qtreeViewFontColorString      = list[36];
// _qtableViewFontColorString     = list[37];
// _qdoubleSpinBoxFontColorString = list[38];
// _qcomboBoxFontColorString      = list[39];
// _qtabWidgetFontColorString     = list[40];
// _qtreeWidgetFontColorString    = list[41];
}

void  MainWindow::themeDefualt()
{
  _qwidget                       = "QWidget{background-color:;}";             // list[0]
  _qlineEdit                     = "QLineEdit{background-color:;}";           // list[1]
  _qradioButton                  = "QRadioButton{background-color:;}";        // list[2]
  _qcheckBox                     = "QCheckBox{background-color:;}";           // list[3]
  _qlabel                        = "QLabel{background-color:;}";              // list[4]
  _qgroupBox                     = "QGroupBox{background-color:;}";           // list[5]
  _qspinBox                      = "QSpinBox{background-color:;}";            // list[6]
  _qpushButton                   = "QPushButton{background-color:;}";         // list[7]
  _qtreeView                     = "QTreeView{background-color:;}";           // list[8]
  _qtableView                    = "QTableView{background-color:;}";          // list[9]
  _qdoubleSpinBox                = "QDoubleSpinBox{background-color:;}";      // list[10]
  _qcomboBox                     = "QComboBox{background-color:;}";           // list[11]
  _qtabWidget                    = "QTabWidget{background-color:;}";          // list[12]
  _qtreeWidget                   = "QTreeWidget{background-color:;}";         // list[13]
  _qwidgetFontString             = "QWidget{font:;}";                         // list[14]
  _qlineEditFontString           = "QLineEdit{font:;}";                       // list[15]
  _qradioButtonFontString        = "QRadioButton{font:;}";                    // list[16]
  _qcheckBoxFontString           = "QCheckBox{font:;}";                       // list[17]
  _qlabelFontString              = "QLabel{font:;}";                          // list[18]
  _qgroupBoxFontString           = "QGroupBox{font:;}";                       // list[19]
  _qspinBoxFontString            = "QSpinBox{font:;}";                        // list[20]
  _qpushButtonFontString         = "QPushButton{font:;}";                     // list[21]
  _qtreeViewFontString           = "QTreeView{font:;}";                       // list[22]
  _qtableViewFontString          = "QTableView{font:;}";                      // list[23]
  _qdoubleSpinBoxFontString      = "QDoubleSpinBox{font:;}";                  // list[24]
  _qcomboBoxFontString           = "QComboBox{font:;}";                       // list[25]
  _qtabWidgetFontString          = "QTabWidget{font:;}";                      // list[26]
  _qtreeWidgetFontString         = "QTreeWidget{font:;}";                     // list[27]
  _qwidgetFontColorString        = "QWidget{color:;}";                        // list[28]
  _qlineEditFontColorString      = "QLineEdit{color:;}";                      // list[29]
  _qradioButtonFontColorString   = "QRadioButton{color:;}";                   // list[30]
  _qcheckBoxFontColorString      = "QCheckBox{color:;}";                      // list[31]
  _qlabelFontColorString         = "QLabel{color:;}";                         // list[32]
  _qgroupBoxFontColorString      = "QGroupBox{color:;}";                      // list[33]
  _qspinBoxFontColorString       = "QSpinBox{color:;}";                       // list[34]
  _qpushButtonFontColorString    = "QPushButton{color:;}";                    // list[35]
  _qtreeViewFontColorString      = "QTreeView{color:;}";                      // list[36]
  _qtableViewFontColorString     = "QTableView{color:;}";                     // list[37]
  _qdoubleSpinBoxFontColorString = "QDoubleSpinBox{color:;}";                 // list[38]
  _qcomboBoxFontColorString      = "QComboBox{color:;}";                      // list[39]
  _qtabWidgetFontColorString     = "QTabWidget{color:;}";                     // list[40]
  _qtreeWidgetFontColorString    = "QTreeWidget{color:;}";                    // list[41]

  updateThemeColor();
  updateThemeFont();
  updateThemeFontColor();
}

void  MainWindow::setUpdateTheme()
{
  _ThemeString.clear();

  _ThemeString = _themStringColor + _themStringFont + _themStringFontColor;

  this->setStyleSheet(_ThemeString);
// qDebug() << _ThemeString;
}

// set value style font
QString  MainWindow::valueFontStyle(int type)
{
  QString  resultValueFontStyle;

  switch (type)
  {
  case 0:
    resultValueFontStyle = "";
    break;
  case 1:
    resultValueFontStyle = "italic";
    break;
  case 2:
    resultValueFontStyle = "oblique";
    break;
  }

  return resultValueFontStyle;
}

// set value weight font
QString  MainWindow::valueFontWeight(int weight)
{
  QString  resultValueFontWeight;

  switch (weight)
  {
  case 0:
    resultValueFontWeight = "Thin";
    break;
  case 12:
    resultValueFontWeight = "ExtraLight";
    break;
  case 25:
    resultValueFontWeight = "Light";
    break;
  case 50:
    resultValueFontWeight = "Normal";
    break;
  case 57:
    resultValueFontWeight = "Medium";
    break;
  case 63:
    resultValueFontWeight = "DemiBold";
    break;
  case 75:
    resultValueFontWeight = "Bold";
    break;
  case 81:
    resultValueFontWeight = "ExtraBold";
    break;
  case 87:
    resultValueFontWeight = "Black";
    break;
  }

  return resultValueFontWeight;

// Thin     = 0,    // 100
// ExtraLight = 12, // 200
// Light    = 25,   // 300
// Normal   = 50,   // 400
// Medium   = 57,   // 500
// DemiBold = 63,   // 600
// Bold     = 75,   // 700
// ExtraBold = 81,  // 800
// Black    = 87    // 900
}

// set standard font code
QString  MainWindow::setAllFont(QFont type)
{
  QString  fontfamily = type.family();
  QString  fontSize   = QString::number(type.pointSize());
  QString  fontWeight = valueFontWeight(type.weight());
  QString  fontStyle  = valueFontStyle(type.style());
  QString  result     = QString("{font: %1 %2 %3pt  %4 ;}").arg(fontWeight).arg(fontStyle).arg(fontSize).arg(fontfamily);

  return result;
}

// set theme

void  MainWindow::on_btn_setTheme_clicked()
{
  setUpdateTheme();
}

// Gradient calc Color
QString  MainWindow::setColorGradient(QColor color)
{
  QString  strColor;
  int      r = color.red();
  int      g = color.green();
  int      b = color.blue();
  int      a = color.alpha();

  strColor = QString("%1, %2 ,%3, %4").arg(r).arg(g).arg(b).arg(a);
  qDebug() << strColor;

  return strColor;
}

// set Gradient 2 colors
bool  MainWindow::setValueColor()
{
  bool    ok1;
  bool    ok2;
  QColor  color1;
  QColor  color2;

  _colorString1.clear();
  _colorString2.clear();

  color1        = QColorDialog::getRgba(0xffffffff, &ok1);
  _colorString1 = setColorGradient(color1);

  color2        = QColorDialog::getRgba(0xffffffff, &ok2);
  _colorString2 = setColorGradient(color2);

  if (ok1 && ok2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void  MainWindow::on_btn_testThemeCode_clicked()
{
  testTheme->setModal(true);
  testTheme->exec();
}

void  MainWindow::on_btn_ShowCurrentCode_clicked()
{
  emit  sendCodeTheme(_ThemeString);

  showTheme->setModal(true);
  showTheme->exec();
}
