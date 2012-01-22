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
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
      items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(1))));
    SelectionTree->insertTopLevelItems(0, items);
    SelectionLayout->addWidget(SelectionTree);

    // DemoToolBar layer (top of demo layer)
    QHBoxLayout *DemoToolBarLayout = new QHBoxLayout;
    DemoLayout->addLayout(DemoToolBarLayout);

    QLabel *label = new QLabel;
    label->setText("testsdfvsdF");
    DemoToolBarLayout->addWidget(label);

    // Create an OGLDemo
    SampleDemo *sampleDemo = new SampleDemo;
    sampleDemo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    DemoLayout->addWidget(sampleDemo);

    MainFrame->show();

    return App.exec();
}
