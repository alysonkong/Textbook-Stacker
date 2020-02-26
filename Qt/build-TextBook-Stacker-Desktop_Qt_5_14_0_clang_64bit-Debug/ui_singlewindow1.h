/********************************************************************************
** Form generated from reading UI file 'singlewindow1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEWINDOW1_H
#define UI_SINGLEWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_singlewindow1
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *pushButton1;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QFrame *frame;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;

    void setupUi(QDialog *singlewindow1)
    {
        if (singlewindow1->objectName().isEmpty())
            singlewindow1->setObjectName(QString::fromUtf8("singlewindow1"));
        singlewindow1->resize(834, 587);
        singlewindow1->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);"));
        verticalLayoutWidget = new QWidget(singlewindow1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(679, 10, 160, 127));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_2);

        pushButton1 = new QPushButton(verticalLayoutWidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));

        verticalLayout->addWidget(pushButton1);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalLayoutWidget_2 = new QWidget(singlewindow1);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(158, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_3, 0, Qt::AlignHCenter|Qt::AlignBottom);

        label_3->raise();
        label->raise();
        frame = new QFrame(singlewindow1);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 100, 161, 101));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        line = new QFrame(singlewindow1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(163, 10, 20, 581));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(singlewindow1);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(170, 570, 491, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(singlewindow1);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(660, 10, 20, 571));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(singlewindow1);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(170, 10, 501, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        retranslateUi(singlewindow1);
        QObject::connect(pushButton, SIGNAL(clicked()), singlewindow1, SLOT(on_pushButton_clicked()));

        QMetaObject::connectSlotsByName(singlewindow1);
    } // setupUi

    void retranslateUi(QDialog *singlewindow1)
    {
        singlewindow1->setWindowTitle(QCoreApplication::translate("singlewindow1", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("singlewindow1", "Player 1 name", nullptr));
        pushButton1->setText(QCoreApplication::translate("singlewindow1", "Pause", nullptr));
        pushButton_2->setText(QCoreApplication::translate("singlewindow1", "Exit", nullptr));
        pushButton->setText(QCoreApplication::translate("singlewindow1", "Go to Main Window", nullptr));
        label->setText(QCoreApplication::translate("singlewindow1", "Score: 0", nullptr));
        label_3->setText(QCoreApplication::translate("singlewindow1", "Textbook", nullptr));
    } // retranslateUi

};

namespace Ui {
    class singlewindow1: public Ui_singlewindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEWINDOW1_H
