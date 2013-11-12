#include "mainwindow.h"
#include <QtGui>
#include <QMouseEvent>
#include <QBrush>

MyGraphics::MyGraphics (QWidget *obj):
    QWidget(obj)
{
    gi=0;
}
void MyGraphics::paintEvent(QPaintEvent *){
    QPainter p(this);
    int i;
    char tmp[50];
    strcpy(tmp,"");
    //QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
   // p.setPen(pen);
    p.setBrush(QBrush(Qt::black));
    for(i=0;i<gi-1;++i){
        if(gy[i]>CB_Y+CB_HEIGHT)
            p.drawPoint(QPointF(gx[i],gy[i]));
    }
    if(gx[i]==-1)
        strcpy(tmp," MOUSE PRESSED");
    else
        sprintf(tmp,"COORDS ARE - %d,%d", gx[i],gy[i]);


}

void MyGraphics::mouseMoveEvent(QMouseEvent *b){
    gx[gi]=b->x();
    gy[gi]=b->y();
    if(gi<N_POINTS-1)
        ++gi;
   repaint();
}
void MyGraphics::mousePressEvent(QMouseEvent *b){
    gx[gi]=b->x();
    gy[gi]=b->y();
    if(gx[gi]>CB_X && gx[gi]<CB_X+CB_WIDTH &&
       gy[gi]> CB_Y && gy[gi]< CB_Y+CB_HEIGHT)
        gi=0;

    if(gx[gi]>EB_X && gx[gi]<EB_X+EB_WIDTH &&
       gy[gi]> EB_Y && gy[gi]< EB_Y+EB_HEIGHT)
       exit(0);
    gx[gi]=-1;
    gy[gi]=-1;
    if(gi<N_POINTS -1)
        ++gi;
    repaint();
}
