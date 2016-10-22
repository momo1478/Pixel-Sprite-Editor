#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QWidget>
#include <vector>
#include <QPixmap>

namespace ui {
class Model;
}

class Model: public QWidget
{
    Q_OBJECT
public:
    Model(QWidget *parent = 0);



protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

public slots:
    void undoButtonClicked();
    void redoButtonClicked();
    void penButtonClicked();
    void eraserButtonClicked();
    void rectButtonClicked();
    void lineButtonClicked();
    void colorPickerButtonClicked();
    void colorCasterButtonClicked();
    void bucketButtonClicked();
    void mirrorButtonClicked();
    void rotateButtonClicked();
    void flipButtonClicked();

    void previewButtonClicked();
    void addFrameButtonClicked();
    void duplicateFrameButtonClicked();
    void removeFrameButtonClicked();



private:
    std::vector<QImage> frames;
    int currentFrame;

    QImage image;
    int scale;

    void draw(QPoint);
    QPoint lastPoint;

    enum Tool {Pen, Eraser};
    int currentTool;
};

#endif // MODEL_H
