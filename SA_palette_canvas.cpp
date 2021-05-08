#include "SA_palette_canvas.h"

BEGIN_EVENT_TABLE(SAPaletteCanvas, wxHVScrolledWindow)
	EVT_MOUSE_EVENTS(SAPaletteCanvas::OnMouseEvent)
END_EVENT_TABLE()

SAPaletteCanvas::SAPaletteCanvas(wxWindow *parent)
	: wxHVScrolledWindow(parent)
{
	m_pView = NULL;
}

SAPaletteCanvas::~SAPaletteCanvas()
{
}

void SAPaletteCanvas::OnDraw(wxDC &dc)
{
	if (m_pView) m_pView->OnDraw(& dc);
}

void SAPaletteCanvas::OnMouseEvent(wxMouseEvent &event)
{
}
