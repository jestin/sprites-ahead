#include "canvas.h"
#include "editor_frame.h"
#include <wx/dcbuffer.h>

wxBEGIN_EVENT_TABLE(Canvas, wxHVScrolledWindow)
	EVT_PAINT(Canvas::OnPaint)
	EVT_MOUSEWHEEL(Canvas::OnMouseWheel)
wxEND_EVENT_TABLE()

Canvas::Canvas(wxWindow *parent)
	: wxHVScrolledWindow(parent)
{
	SetRowColumnCount(40, 40);
	SetBackgroundStyle(wxBG_STYLE_PAINT);
}

Canvas::~Canvas()
{
}

void Canvas::OnMouseWheel(wxMouseEvent& event)
{
	int newPixelSize;

	if(event.GetWheelRotation() > 0) {
		newPixelSize = (int)(m_nPixelSize * 1.5);
		wxCanvasEvent canvasEvent(wxEVT_CANVAS_ZOOM_IN, GetId());
		canvasEvent.SetEventObject(this);
		canvasEvent.zoom = newPixelSize;
		GetEventHandler()->ProcessEvent(canvasEvent);
	} else
	{
		newPixelSize = (int)(m_nPixelSize / 1.5);
		wxCanvasEvent canvasEvent(wxEVT_CANVAS_ZOOM_OUT, GetId());
		canvasEvent.SetEventObject(this);
		canvasEvent.zoom = newPixelSize;
		GetEventHandler()->ProcessEvent(canvasEvent);
	}

	if(newPixelSize > 1)
	{
		SetPixelSize(newPixelSize);
	}

	wxCanvasEvent changedEvent(wxEVT_CANVAS_ZOOM_CHANGED, GetId());
	changedEvent.SetEventObject(this);
	changedEvent.zoom = newPixelSize;
	GetEventHandler()->ProcessEvent(changedEvent);
}

void Canvas::SetPixelSize(int n)
{
	m_nPixelSize = n;
	wxVarHScrollHelper::RefreshAll();
	wxVarVScrollHelper::RefreshAll();
	Refresh();
}

wxCoord Canvas::OnGetRowHeight(size_t) const
{
	return wxCoord(m_nPixelSize);
}

wxCoord Canvas::OnGetColumnWidth(size_t) const
{
	return wxCoord(m_nPixelSize);
}

void Canvas::OnDraw(wxDC& dc)
{
	dc.Clear();

	wxBrush brush = dc.GetBrush();
	wxPen pen = dc.GetPen();

	wxPosition s = GetVisibleBegin();
	wxPosition e = GetVisibleEnd();

	pen.SetStyle(wxPENSTYLE_LONG_DASH);
	pen.SetColour(wxColour(200, 200, 200));
	dc.SetPen(pen);

	for(int y = s.GetRow(); y < e.GetRow(); y++)
	{
		for(int x = s.GetCol(); x < e.GetCol(); x++)
		{
			dc.SetBrush(brush);
			dc.DrawRectangle(
					x * m_nPixelSize,
					y *m_nPixelSize,
					m_nPixelSize,
					m_nPixelSize);
		}
	}

	brush.SetColour(wxColour(255, 255, 255));
	dc.SetBrush(brush);

	// dc.DrawRectangle(20, 20, 200, 200);
}

void Canvas::OnPaint(wxPaintEvent& event)
{
	wxBufferedPaintDC dc(this);
	this->PrepareDC(dc);
	this->OnDraw(dc);
}
