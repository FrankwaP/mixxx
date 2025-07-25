#include "hsvwaveformwidget.h"

#include <QPainter>

#include "moc_hsvwaveformwidget.cpp"
#include "waveform/renderers/waveformrenderbackground.h"
#include "waveform/renderers/waveformrenderbeat.h"
#include "waveform/renderers/waveformrendererendoftrack.h"
#include "waveform/renderers/waveformrendererhsv.h"
#include "waveform/renderers/waveformrendererpreroll.h"
#include "waveform/renderers/waveformrendermark.h"
#include "waveform/renderers/waveformrendermarkrange.h"

HSVWaveformWidget::HSVWaveformWidget(const QString& group,
        QWidget* parent,
        ::WaveformRendererSignalBase::Options options)
        : NonGLWaveformWidgetAbstract(group, parent) {
    addRenderer<WaveformRenderBackground>();
    addRenderer<WaveformRendererEndOfTrack>();
    addRenderer<WaveformRendererPreroll>();
    addRenderer<WaveformRenderMarkRange>();
    addRenderer<WaveformRendererHSV>(options);
    addRenderer<WaveformRenderBeat>();
    addRenderer<WaveformRenderMark>();

    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_OpaquePaintEvent);

    m_initSuccess = init();
}

HSVWaveformWidget::~HSVWaveformWidget() {
}

void HSVWaveformWidget::castToQWidget() {
    m_widget = this;
}

void HSVWaveformWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    draw(&painter,event);
}
