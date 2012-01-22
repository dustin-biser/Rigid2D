#include <Qt/qapplication.h>
#include <Qt/qframe.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QFrame>
#include <QLabel>
#include <QGLWidget>
#include "SampleDemo.h"


int main(int argc, char **argv)
{
    QApplication App(argc, argv);

    // Create the main frame
    QFrame *MainFrame = new QFrame;
    MainFrame->setWindowTitle("Qt SFML");
    MainFrame->resize(800, 800);
    QHBoxLayout *MainLayout = new QHBoxLayout;
    MainFrame->setLayout(MainLayout);
    
    //// Create the selection frame (left)
    //QWidget *SelectionFrame = new QWidget;
    QVBoxLayout *SelectionLayout = new QVBoxLayout;
    //SelectionFrame->setLayout(SelectionLayout);
    //MainLayout->addWidget(SelectionFrame);
    MainLayout->addLayout(SelectionLayout);

    // Create the demo frame (right)
    //QFrame *DemoFrame = new QFrame;
  	QVBoxLayout *DemoLayout = new QVBoxLayout;
	  //DemoFrame->setLayout(DemoLayout);
	  //MainLayout->addWidget(DemoFrame);
    MainLayout->addLayout(DemoLayout);

    
    // Create TreeWidget in the right layout
    QTreeWidget *SelectionTree = new QTreeWidget;
    SelectionTree->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
      items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(1))));
    SelectionTree->insertTopLevelItems(0, items);
    SelectionLayout->addWidget(SelectionTree);

    // Create an OGLDemo
    SampleDemo *sampleDemo = new SampleDemo;
    DemoLayout->addWidget(sampleDemo);

    QLabel *label = new QLabel;
    label->setText("testsdfvsdF");
    DemoLayout->addWidget(label);

    MainFrame->show();

    return App.exec();
}
