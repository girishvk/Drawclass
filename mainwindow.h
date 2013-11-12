#include <QtGui>
#include <QWidget>

#define N_POINTS 1000
// Clear Button
#define CB_X    0
#define CB_Y    0
#define CB_WIDTH    200
#define CB_HEIGHT 50

//Exit Button
#define EB_X 201
#define EB_Y 0
#define EB_WIDTH 200
#define EB_HEIGHT 50

//Button Text Offsets
#define BT_X 30
#define BT_Y 30

// Message Location
#define MESS_X 30
#define MESS_Y 380

class MyGraphics: public QWidget {
    Q_OBJECT

public:
    MyGraphics (QWidget* obj=0);
    virtual void paintEvent(QPaintEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);

private:
    int gx[N_POINTS],gy[N_POINTS];
    int gi;
};
