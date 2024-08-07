/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *button45;
    QPushButton *button90;
    QPushButton *button180;
    QLabel *lablel_2;
    QSlider *verticalSlider;
    QGraphicsView *graphicsView;
    QPushButton *button0;
    QLabel *label;
    QPushButton *button135;
    QLabel *detectionStatusLabel;
    QPushButton *button_auto;
    QLabel *angleLabel;
    QLabel *rangeLabel;
    QLabel *heightLabel;
    QTextEdit *textEdit;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1021, 821);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        button45 = new QPushButton(centralwidget);
        button45->setObjectName("button45");
        button45->setGeometry(QRect(10, 580, 81, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(16);
        button45->setFont(font);
        button90 = new QPushButton(centralwidget);
        button90->setObjectName("button90");
        button90->setGeometry(QRect(10, 630, 81, 41));
        button90->setFont(font);
        button180 = new QPushButton(centralwidget);
        button180->setObjectName("button180");
        button180->setGeometry(QRect(100, 580, 81, 41));
        button180->setFont(font);
        lablel_2 = new QLabel(centralwidget);
        lablel_2->setObjectName("lablel_2");
        lablel_2->setGeometry(QRect(800, 610, 150, 41));
        lablel_2->setMinimumSize(QSize(150, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(22);
        font1.setBold(false);
        lablel_2->setFont(font1);
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(630, 530, 100, 200));
        verticalSlider->setMinimumSize(QSize(100, 200));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        verticalSlider->setFont(font2);
        verticalSlider->setLayoutDirection(Qt::LeftToRight);
        verticalSlider->setMaximum(180);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 1000, 515));
        graphicsView->setMinimumSize(QSize(1000, 515));
        graphicsView->setMaximumSize(QSize(1000, 515));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush3(QColor(255, 255, 255, 127));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush4(QColor(0, 0, 0, 127));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        graphicsView->setPalette(palette);
        button0 = new QPushButton(centralwidget);
        button0->setObjectName("button0");
        button0->setGeometry(QRect(10, 530, 81, 41));
        button0->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(800, 530, 150, 41));
        label->setMinimumSize(QSize(150, 25));
        label->setFont(font1);
        button135 = new QPushButton(centralwidget);
        button135->setObjectName("button135");
        button135->setGeometry(QRect(100, 530, 81, 41));
        button135->setFont(font);
        detectionStatusLabel = new QLabel(centralwidget);
        detectionStatusLabel->setObjectName("detectionStatusLabel");
        detectionStatusLabel->setGeometry(QRect(10, 690, 471, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(26);
        font3.setBold(false);
        detectionStatusLabel->setFont(font3);
        button_auto = new QPushButton(centralwidget);
        button_auto->setObjectName("button_auto");
        button_auto->setGeometry(QRect(100, 630, 131, 41));
        button_auto->setFont(font);
        angleLabel = new QLabel(centralwidget);
        angleLabel->setObjectName("angleLabel");
        angleLabel->setGeometry(QRect(790, 570, 101, 45));
        angleLabel->setMaximumSize(QSize(150, 45));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Times New Roman")});
        font4.setPointSize(28);
        angleLabel->setFont(font4);
        angleLabel->setAutoFillBackground(false);
        rangeLabel = new QLabel(centralwidget);
        rangeLabel->setObjectName("rangeLabel");
        rangeLabel->setGeometry(QRect(760, 650, 175, 45));
        rangeLabel->setMaximumSize(QSize(175, 45));
        rangeLabel->setFont(font4);
        heightLabel = new QLabel(centralwidget);
        heightLabel->setObjectName("heightLabel");
        heightLabel->setGeometry(QRect(760, 730, 171, 51));
        heightLabel->setFont(font4);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(200, 530, 121, 51));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Times New Roman")});
        font5.setPointSize(18);
        textEdit->setFont(font5);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(800, 690, 141, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Times New Roman")});
        font6.setPointSize(22);
        label_2->setFont(font6);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1021, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button45->setText(QCoreApplication::translate("MainWindow", "45", nullptr));
        button90->setText(QCoreApplication::translate("MainWindow", "90", nullptr));
        button180->setText(QCoreApplication::translate("MainWindow", "180", nullptr));
        lablel_2->setText(QCoreApplication::translate("MainWindow", "Range:", nullptr));
        button0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Angle:", nullptr));
        button135->setText(QCoreApplication::translate("MainWindow", "135", nullptr));
        detectionStatusLabel->setText(QCoreApplication::translate("MainWindow", "there", nullptr));
        button_auto->setText(QCoreApplication::translate("MainWindow", "Auto Start", nullptr));
        angleLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rangeLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        heightLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>0</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
