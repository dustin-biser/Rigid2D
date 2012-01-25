#include <Qt/qapplication.h>
#include <Qt/qframe.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QFrame>
#include <QLabel>
#include <QGLWidget>
#include <QPushButton>
#include "SampleDemo.h"


int main(int argc, char **argv)
{
    QApplication App(argc, argv);

    // Create the main frame
    QFrame *MainFrame = new QFrame;
    MainFrame->setWindowTitle("Rigid2D Examples");
    MainFrame->resize(800, 800);
    QHBoxLayout *MainLayout = new QHBoxLayout;
    MainFrame->setLayout(MainLayout);

    // Create layouts for selection and demo
    QVBoxLayout *SelectionLayout = new QVBoxLayout;
  	QVBoxLayout *DemoLayout = new QVBoxLayout;
    DemoLayout->setAlignment(Qt::AlignLeft);
    MainLayout->addLayout(SelectionLayout);
    MainLayout->addLayout(DemoLayout);
    
    // Create TreeWidget in the selection layout
    QTreeWidget *SelectionTree = new QTreeWidget();
    SelectionTree->setMaximumWidth(200);
    SelectionTree->setColumnCount(1);
    SelectionTree->setHeaderLabel(QString("Examples"));
    QTreeWidgetItem *demosHeader = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Demos")));
    SelectionTree->addTopLevelItem(demosHeader);
    QTreeWidgetItem *demo1 = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Demo 1")));
    demosHeader->addChild(demo1);
    SelectionLayout->addWidget(SelectionTree);

    // DemoToolBar layer (top of demo layer)
    QHBoxLayout *DemoToolBarLayout = new QHBoxLayout;
    DemoLayout->addLayout(DemoToolBarLayout);

    // DemoToolBar Buttons
    QPushButton *RunButton = new QPushButton("Run");
    DemoToolBarLayout->addWidget(RunButton);

    // Create an OGLDemo
    SampleDemo *Demo1 = new SampleDemo;
    Demo1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    DemoLayout->addWidget(Demo1);

    // Create an fps display
    QHBoxLayout *FPSLayout = new QHBoxLayout;
    FPSLayout->setAlignment(Qt::AlignRight);
    QLabel *FPSTextLabel = new QLabel("Fps: ");
    QLabel *FPSNumLabel = new QLabel;
    QObject::connect(Demo1, SIGNAL(fpsChanged(int)), FPSNumLabel, SLOT(setNum(int)));
    FPSLayout->addWidget(FPSTextLabel);
    FPSLayout->addWidget(FPSNumLabel);
    DemoLayout->addLayout(FPSLayout);

    MainFrame->show();

    return App.exec();
}
