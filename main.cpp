#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTimer>

class EllipseWidget : public QWidget {
public:
    EllipseWidget(QWidget *parent = nullptr) : QWidget(parent), m_x(0) {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &EllipseWidget::onTimer);
        timer->start(10);
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setBrush(Qt::red);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(m_x, height() / 2, 50, 50);
    }

private slots:
    void onTimer() {
        m_x += 1;
        if (m_x >= width())
            m_x = 0;
        update();
    }

private:
    int m_x;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    EllipseWidget *widget = new EllipseWidget();
    widget->setFixedSize(400, 200);
    widget->show();

    return app.exec();
}
