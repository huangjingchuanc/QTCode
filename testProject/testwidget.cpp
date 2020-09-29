#include "testwidget.h"
#include<QColorDialog>
#include<QDebug>
testWidget::testWidget(QWidget *parent)
    : QWidget(parent)
{

    m_controlLayout=new QGridLayout;
    m_HLayout=new QHBoxLayout(this);
    initPaintArea();
    initAllShape();
    initpenColor();
    initAllLineWith();
    initAllPenStyle();
    initAllPenCapStyle();
    initAllPenLinkDot();
    initAllFillModel();
    initAllSpreadStyle();
    initBrushColor();
    initBrushStyle();
    initConnectSignal();
    m_HLayout->addLayout(m_controlLayout);
}

testWidget::~testWidget()
{
}

void testWidget::initPaintArea()
{
    m_paintArea=new PaintArea;
    m_paintArea->setFixedSize(400,400);
    m_paintArea->setAutoFillBackground(true);
    m_paintArea->setPalette(QPalette(Qt::white));
    m_HLayout->addWidget(m_paintArea);
}

void testWidget::initAllShape()
{
    QString shapeName[11]={"线","矩形","圆角矩形","椭圆","多边形",
                           "多线段","点","弧线","路径","文本","图片"};
    m_shape=new QLabel("形状");
    m_shapeStyleBox=new QComboBox;
    for(int i=0;i<11;i++)
    {
        m_shapeStyleBox->addItem(shapeName[i],PaintArea::LINE+i);
    }
    m_paintArea->setShapeStyle(PaintArea::LINE);

    m_controlLayout->addWidget(m_shape,0,0);
    m_controlLayout->addWidget(m_shapeStyleBox,0,1);

}

void testWidget::initpenColor()
{
    m_penColor=new QLabel("画笔颜色");
    m_penCurrentColor=new QFrame;
    m_penCurrentColor->setFrameShape(QFrame::Box);
    m_penCurrentColor->setAutoFillBackground(true);
    m_penCurrentColor->setPalette(QPalette(Qt::red));
    m_modifyPenColorBtn=new QPushButton("画笔颜色更改");

    m_paintArea->getPen().setColor(Qt::red);
    m_controlLayout->addWidget(m_penColor,1,0);
    m_controlLayout->addWidget(m_penCurrentColor,1,1);
    m_controlLayout->addWidget(m_modifyPenColorBtn,1,2);
}

void testWidget::initAllLineWith()
{
    m_lineWith=new QLabel("线宽");
    m_currentLineWith=new QSpinBox;
    m_currentLineWith->setRange(1,20);

    m_paintArea->getPen().setWidth(1);
    m_controlLayout->addWidget(m_lineWith,2,0);
    m_controlLayout->addWidget(m_currentLineWith,2,1);
}

void testWidget::initAllPenStyle()
{
    m_penStyle=new QLabel("画笔风格");
    m_currentPenStyle=new QComboBox;

    QString penStyle[7]={"无","普通实线","线段","点","一线一点","一线两点","自定义"};
    for(int i=0;i<7;i++)
    {
        m_currentPenStyle->addItem(penStyle[i],i);
    }
    m_paintArea->getPen().setStyle(Qt::NoPen);
    m_controlLayout->addWidget(m_penStyle,3,0);
    m_controlLayout->addWidget(m_currentPenStyle,3,1);
}

void testWidget::initAllPenCapStyle()
{
    m_penCapStyle=new QLabel("笔帽风格");
    m_currentPenCapStyle=new QComboBox;
    QString penCapStyle[3]={"Flat","Square","Round"};
    for(int i=0;i<3;i++){
        m_currentPenCapStyle->addItem(penCapStyle[i],i*16);
    }

    m_controlLayout->addWidget(m_penCapStyle,4,0);
    m_controlLayout->addWidget(m_currentPenCapStyle,4,1);
}

void testWidget::initAllPenLinkDot()
{
    m_penLinkDot=new QLabel("画笔连接点");
    m_penLinkDotType=new QComboBox;
    QString PenLinkDot[4]={"Miter","Bevel","Round","SvgMiter"};
    for(int i=0;i<4;i++){
        m_penLinkDotType->addItem(PenLinkDot[i],i+64);
    }

    m_controlLayout->addWidget(m_penLinkDot,5,0);
    m_controlLayout->addWidget(m_penLinkDotType,5,1);
}

void testWidget::initAllFillModel()
{
    m_fillModel=new QLabel("填充模式");
    m_currentFillModel=new QComboBox;
    m_currentFillModel->addItem("Oddevent",Qt::OddEvenFill);
    m_currentFillModel->addItem("Winding",Qt::WindingFill);

    m_controlLayout->addWidget(m_fillModel,6,0);
    m_controlLayout->addWidget(m_currentFillModel,6,1);
}

void testWidget::initAllSpreadStyle()
{
   m_spreadStyle=new QLabel("铺展效果");
    m_currentSpreadStyle=new QComboBox;
    m_currentSpreadStyle->addItem("PadSpread",QGradient::PadSpread);
    m_currentSpreadStyle->addItem("RepeatSpread",QGradient::RepeatSpread);
    m_currentSpreadStyle->addItem("ReflectSpread",QGradient::ReflectSpread);

    m_controlLayout->addWidget(m_spreadStyle,7,0);
    m_controlLayout->addWidget(m_currentSpreadStyle,7,1);
}

void testWidget::initBrushColor()
{
    m_brushColor=new QLabel("画刷颜色");
    m_currentBrushColor=new QFrame;
    m_currentBrushColor->setAutoFillBackground(true);
    m_currentBrushColor->setFrameShape(QFrame::Box);
    m_currentBrushColor->setPalette(Qt::red);
    m_modifyBrushColorBtn=new QPushButton("画刷颜色更改");

    m_controlLayout->addWidget(m_brushColor,8,0);
    m_controlLayout->addWidget(m_currentBrushColor,8,1);
    m_controlLayout->addWidget( m_modifyBrushColorBtn,8,2);
}

void testWidget::initBrushStyle()
{
    m_brushStyle=new QLabel("画刷风格");
    m_currentBrushStyle=new QComboBox;
    QString brushStyle[18]={"noBrush","SolidPattern","Dense1Pattern","Dense2Pattern","Dense3Pattern",
                           "Dense4Pattern","Dense5Pattern","Dense6Pattern","Dense7Pattern","HorPattern",
                           "VerPattern","CrossPattern","BDiagPattern","FDiagPattern","DiagCrossPattern",
                           "LinearGradientPattern","ConicalGradientPattern","RadialGradientPattern"};
    for(int i=0;i<18;i++){
        m_currentBrushStyle->addItem(brushStyle[i],i);
    }
    m_currentBrushStyle->addItem("TexturePattern",24);

     m_controlLayout->addWidget(m_brushStyle,9,0);
     m_controlLayout->addWidget(m_currentBrushStyle,9,1);
}

void testWidget::initConnectSignal()
{
    connect(m_shapeStyleBox,SIGNAL(currentIndexChanged(int)),this,SLOT(shapeChange(int)));
    connect(m_modifyPenColorBtn,SIGNAL(clicked()),this,SLOT(penColorChange()));
    connect(m_currentLineWith,SIGNAL(valueChanged(int)),this,SLOT(lineWithChange(int)));
    connect(m_currentPenStyle,SIGNAL(currentIndexChanged(int)),this,SLOT(penStyleChange(int)));
    connect(m_currentPenCapStyle,SIGNAL(currentIndexChanged(int)),this,SLOT(penCapStyleChange(int)));
}

void testWidget::shapeChange(int index)
{
    PaintArea::Shape shape=PaintArea::Shape(m_shapeStyleBox->itemData(index).toInt());
    m_paintArea->setShapeStyle(shape);
}

void testWidget::penColorChange()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"画笔颜色选择");
    QPen pen=m_paintArea->getPen();
    pen.setColor(color);
    m_paintArea->setPenStyle(pen);
}

void testWidget::lineWithChange(int value)
{
    QPen pen=m_paintArea->getPen();
    pen.setWidth(value);
    m_paintArea->setPenStyle(pen);
}

void testWidget::penStyleChange(int index)
{
    QPen pen=m_paintArea->getPen();
    Qt::PenStyle penStyle=Qt::PenStyle(m_currentPenStyle->itemData(index).toInt());
    pen.setStyle(penStyle);
    m_paintArea->setPenStyle(pen);

}

void testWidget::penCapStyleChange(int index)
{
    QPen pen=m_paintArea->getPen();
    Qt::PenCapStyle capStyle=Qt::PenCapStyle(m_currentPenCapStyle->itemData(index).toInt());
    pen.setCapStyle(capStyle);
    m_paintArea->setPenStyle(pen);
}

void testWidget::penLinkChange(int index)
{

}

void testWidget::fillModelChange(int index)
{

}

void testWidget::spreadStyleChange(int index)
{

}

void testWidget::brushColorChange()
{

}

void testWidget::brushStyleChange(int index)
{

}

