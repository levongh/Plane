#include <QApplication>
#include <QDockWidget>
#include <QTabWidget>
#include <QLabel>
#include <QGridLayout>
#include <QFrame>
#include <QLineEdit>
#include <QGraphicsView>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

#include "MainWindow.h"
#include "twodimentionalscene.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_zoomFactor(1)
    , m_zoomStep(1.1)
{
    m_scene = new TwoDimentionalScene;
    m_mainLayout = new QVBoxLayout;

    m_centralWidget = new QWidget;
    m_2dView = new QGraphicsView(m_scene);



    m_mainLayout->addWidget(m_2dView);

    m_centralWidget->setLayout(m_mainLayout);
    setCentralWidget(m_centralWidget);

    createDockWidgets();
    createConnections();
    createMenus();
    setWindowTitle("Plane");
    setMinimumSize(900, 600);
}

void MainWindow::createConnections()
{
    connect(m_scene, SIGNAL(antenaPosChanged(QPointF, unsigned int)), this, SLOT(antennaPosChanged(QPointF, unsigned int)));
    connect(m_scene, SIGNAL(planePosChanged(QPointF)), this, SLOT(planePosChanged(QPointF)));
    connect(m_scene, SIGNAL(zoomChanged(double)), this, SLOT(updateZoomFactor(double)));
}

void MainWindow::fillDockWidget(QGridLayout* grid, QLineEdit* _x, QLineEdit* _y, QLineEdit* _z)
{
    static int count = 1;
    QHBoxLayout * x_hor = new QHBoxLayout;
    QLabel *x_lab = new QLabel("X:");
    x_hor->addWidget(x_lab);
    x_hor->addWidget(_x);
    grid->addLayout(x_hor, count++, 0);

    QHBoxLayout * y_hor = new QHBoxLayout;
    QLabel *y_lab = new QLabel("Y:");
    y_hor->addWidget(y_lab);
    y_hor->addWidget(_y);
    grid->addLayout(y_hor, count++, 0);

    QHBoxLayout *z_hor = new QHBoxLayout;
    QLabel *z_lab = new QLabel("Z:");
    z_hor->addWidget(z_lab);
    z_hor->addWidget(_z);
    grid->addLayout(z_hor, count++, 0);

    ++count;
}

QWidget* MainWindow::createSettingsTab()
{
    m_settingsWidget =new QWidget;
    createLineEdites();
    QGridLayout *rightDockLayout = new QGridLayout(m_settingsWidget);
    antena1 = new QLabel(tr("Antena 1 configurations"));
    antena1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    rightDockLayout->addWidget(antena1, 0, 0);
    fillDockWidget(rightDockLayout, antena1_x, antena1_y, antena1_z);

    antena2 = new QLabel(tr("Antena 2 configurations"));
    antena2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    rightDockLayout->addWidget(antena2, 4, 0);
    fillDockWidget(rightDockLayout, antena2_x, antena2_y, antena2_z);

    antena3 = new QLabel(tr("Antena 3 configurations"));
    antena3->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    rightDockLayout->addWidget(antena3, 8, 0);
    fillDockWidget(rightDockLayout, antena3_x, antena3_y, antena3_z);

    antena4 = new QLabel(tr("Antena 4 configurations"));
    antena4->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    rightDockLayout->addWidget(antena4, 12, 0);
    fillDockWidget(rightDockLayout, antena4_x, antena4_y, antena4_z);

    antena5 = new QLabel(tr("Antena 5 configurations"));
    antena5->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    rightDockLayout->addWidget(antena5, 16, 0);
    fillDockWidget(rightDockLayout, antena5_x, antena5_y, antena5_z);

    plane = new QLabel(tr("Plane information"));
    plane->setFrameStyle((QFrame::Panel | QFrame::Sunken));
    plane->setStyleSheet("QLabel { background-color : red; color : blue; }");
    rightDockLayout->addWidget(plane, 20, 0);
    fillDockWidget(rightDockLayout, plane_x, plane_y, plane_z);

    QVBoxLayout *l = new QVBoxLayout;
    l->addStretch();
    rightDockLayout->addLayout(l, 24, 0);

    //TODO add line edits and their normal setting input windows
    return m_settingsWidget;
}

void MainWindow::createDockWidgets()
{
    m_rightDock = new QDockWidget(tr("Properties"));
    m_rightDock->setAllowedAreas( Qt::RightDockWidgetArea);
    m_rightDock->setFeatures( QDockWidget::NoDockWidgetFeatures );
    m_rightDock->setMinimumWidth(150);

    m_rightDockTabWidget = new QTabWidget(this);
    m_rightDockTabWidget->addTab(createSettingsTab(), "Settings");
    m_rightDock->setWidget(m_rightDockTabWidget);
    addDockWidget(Qt::RightDockWidgetArea, m_rightDock);
}


void MainWindow::createLineEdites()
{
    antena1_x = new QLineEdit;
    antena1_y = new QLineEdit;
    antena1_z = new QLineEdit;

    antena2_x = new QLineEdit;
    antena2_y = new QLineEdit;
    antena2_z = new QLineEdit;

    antena3_x = new QLineEdit;
    antena3_y = new QLineEdit;
    antena3_z = new QLineEdit;

    antena4_x = new QLineEdit;
    antena4_y = new QLineEdit;
    antena4_z = new QLineEdit;

    antena5_x = new QLineEdit;
    antena5_y = new QLineEdit;
    antena5_z = new QLineEdit;

    plane_x = new QLineEdit;
    plane_y = new QLineEdit;
    plane_z = new QLineEdit;
}


//slots
void MainWindow::antennaPosChanged(QPointF pos, unsigned int id)
{
    switch(id){
    case 0:
        antena1_x->setText(QString::number(pos.x(), 'f', 4));
        antena1_y->setText(QString::number(pos.y(), 'f', 4));
        break;
    case 1:
        antena2_x->setText(QString::number(pos.x(), 'f', 4));
        antena2_y->setText(QString::number(pos.y(), 'f', 4));
        break;
    case 2:
        antena3_x->setText(QString::number(pos.x(), 'f', 4));
        antena3_y->setText(QString::number(pos.y(), 'f', 4));
        break;
    case 3:
        antena4_x->setText(QString::number(pos.x(), 'f', 4));
        antena4_y->setText(QString::number(pos.y(), 'f', 4));
        break;
    case 4:
        antena5_x->setText(QString::number(pos.x(), 'f', 4));
        antena5_y->setText(QString::number(pos.y(), 'f', 4));
        break;
    }

}

void MainWindow::planePosChanged(QPointF pos)
{
    plane_x->setText(QString::number(pos.x(), 'f', 4));
    plane_y->setText(QString::number(pos.y(), 'f', 4));
}
void MainWindow::updateZoomFactor(double zoom)
{
    if (zoom > 0 && m_zoomFactor < 20) {
        m_zoomFactor += m_zoomStep;
        m_2dView->scale(m_zoomStep, m_zoomStep);
        m_scene->update();
        return;
    } else if (zoom < 0 && m_zoomFactor > -12){
        m_zoomFactor -= m_zoomStep;
        m_2dView->scale(1.0/m_zoomStep, 1.0/m_zoomStep);
        m_scene->update();
        return;
    }
    m_scene->update();
}

void MainWindow::createMenus()
{
    createActions();
    m_toolBar = new QToolBar("File");
    m_mainMenu = menuBar()->addMenu(tr("Simulation"));
    m_mainMenu->addAction(m_playAction);
    m_mainMenu->addAction(m_solveAction);
    m_mainMenu->addSeparator();
    m_mainMenu->addAction(m_exitAction);

    //add actions in tool bar
    m_toolBar->addAction(m_playAction);
    m_toolBar->addAction(m_solveAction);
    m_toolBar->addAction(m_exitAction);
    //add tool bar to main window

    m_toolBar->addAction(m_3dPloter);
    addToolBar(m_toolBar);
}

void MainWindow::createActions()
{
    m_playAction = new QAction(QIcon(":/images/play.png"), tr("&Play"), this);
    connect(m_playAction, SIGNAL(triggered(bool)), m_scene, SLOT(startPlaying()));

    //mainToolBar->addAction(m_playAction);
    m_solveAction = new QAction(QIcon(":/images/solve.png"), tr("&Solve"), this);
    connect(m_solveAction, SIGNAL(triggered(bool)), this, SLOT(solveProblem()));

    m_3dPloter = new QAction(QIcon(":/images/3d.png"), tr("3D Window") /* this ? */);
    connect(m_3dPloter, SIGNAL(triggered(bool)), this, SLOT(on3DPloterGetting()));

    m_exitAction = new QAction(QIcon(":/images/exit.png"), tr("&Exit"), this);
    connect(m_exitAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
}

void MainWindow::solveProblem()
{

}
