#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include<QLabel>
#include<QComboBox>
#include<QPushButton>
#include<QSpinBox>
#include<QGridLayout>
#include<QHBoxLayout>
#include"paintarea.h"
class testWidget : public QWidget
{
    Q_OBJECT

public:
    testWidget(QWidget *parent = nullptr);
    ~testWidget();
    void initPaintArea();   //初始化绘图区域
    void initAllShape();    //初始化所有可选形状
    void initpenColor();    //初始化当前画笔颜色
    void initAllLineWith(); //初始化所有可选线宽
    void initAllPenStyle(); //初始化所有画笔风格
    void initAllPenCapStyle();  //初始化所有笔帽风格
    void initAllPenLinkDot();   //初始化所有画笔连接点
    void initAllFillModel();    //初始化所有填充模式
    void initAllSpreadStyle();  //初始化所有铺展效果
    void initBrushColor();  //初始化画刷颜色
    void initBrushStyle();  //初始化所有画刷风格

    void initConnectSignal();//初始化信号连接

public slots:
    void shapeChange(int index);//形状改变
    void penColorChange();//画笔颜色改变
    void lineWithChange(int value);//线宽改变
    void penStyleChange(int index);//画笔风格改变
    void penCapStyleChange(int index);//画笔笔帽风格改变
    void penLinkChange(int index);//画笔连接改变
    void fillModelChange(int index);//填充模式改变
    void spreadStyleChange(int index);//铺展效果改变
    void brushColorChange();//画刷颜色改变
    void brushStyleChange(int index);//画刷风格改变
private:
    PaintArea *m_paintArea;//画图区域

    QLabel  *m_shape;//形状
    QComboBox *m_shapeStyleBox;

    QLabel *m_penColor;//画笔颜色
    QFrame *m_penCurrentColor;
    QPushButton *m_modifyPenColorBtn;

    QLabel  *m_lineWith;//线宽
    QSpinBox *m_currentLineWith;

    QLabel *m_penStyle;//画笔风格
    QComboBox *m_currentPenStyle;

    QLabel *m_penCapStyle;//笔帽风格
    QComboBox *m_currentPenCapStyle;

    QLabel *m_penLinkDot;//画笔连接点
    QComboBox *m_penLinkDotType;

    QLabel *m_fillModel;//填充模式
    QComboBox *m_currentFillModel;

    QLabel *m_spreadStyle;//铺展效果
    QComboBox *m_currentSpreadStyle;

    QLabel *m_brushColor;//画刷颜色
    QFrame *m_currentBrushColor;
    QPushButton *m_modifyBrushColorBtn;

    QLabel *m_brushStyle;//画刷风格
    QComboBox *m_currentBrushStyle;

    QGridLayout *m_controlLayout;//控件布局管理器
    QHBoxLayout *m_HLayout;

};
#endif // TESTWIDGET_H
