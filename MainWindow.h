#pragma once

#include <QMainWindow>

class MainWidget;
class QMenu;
class QMenuBar;
class QAction;
class QToolBar;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QDockWidget;
class QTabWidget;
class QWidget;
class QLineEdit;
class QLabel;
class QGridLayout;
class graphicsScene;
class QGraphicsView;

class Antenna;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void updateZoomFactor(double);
    void solveProblem();

public slots:
    void antennaPosChanged(QPointF pos, unsigned int id);
    void planePosChanged(QPointF pos);

private:
    void createMenus();
    void createActions();
    void createToolBars();
    void createLineEdites();
    void createConnections();

private:
    void fillDockWidget(QGridLayout* grid, QLineEdit* _x, QLineEdit* _y, QLineEdit* _z);
    void createDockWidgets();
    QWidget* createSettingsTab();

    //@brief settings widget attributes
private:
    //antena1
    QLabel *antena1;
    QLineEdit *antena1_x;
    QLineEdit *antena1_y;
    QLineEdit *antena1_z;
    //antena2
    QLabel *antena2;
    QLineEdit *antena2_x;
    QLineEdit *antena2_y;
    QLineEdit *antena2_z;
    //antena3
    QLabel *antena3;
    QLineEdit *antena3_x;
    QLineEdit *antena3_y;
    QLineEdit *antena3_z;
    //antena4
    QLabel *antena4;
    QLineEdit *antena4_x;
    QLineEdit *antena4_y;
    QLineEdit *antena4_z;
    //antena5
    QLabel *antena5;
    QLineEdit *antena5_x;
    QLineEdit *antena5_y;
    QLineEdit *antena5_z;
    //plane
    QLabel *plane;
    QLineEdit *plane_x;
    QLineEdit *plane_y;
    QLineEdit *plane_z;

    //@brief main window mebers
private:
    graphicsScene *m_scene;
    QDockWidget *m_rightDock;
    QTabWidget *m_rightDockTabWidget;
    QWidget *m_settingsWidget;

private:
    QGraphicsView* m_2dView;
    QVBoxLayout* m_mainLayout;
    graphicsScene* m_cene;
    QWidget* m_centralWidget;

private:
    double m_zoomFactor;
    double m_zoomStep;

private:
    QMenu *m_mainMenu;
    QToolBar *m_toolBar;
    QAction *m_playAction;
    QAction *m_solveAction;
    QAction *m_exitAction;

};
