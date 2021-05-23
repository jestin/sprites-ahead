#pragma once

#include <wx/wx.h>
#include <wx/vscroll.h>
#include "canvas_event.h"

class Canvas : public wxHVScrolledWindow
{
	public:
		Canvas(wxWindow *parent);
		~Canvas();

		void SetPixelSize(int n);

	private:
		int m_nPixelSize = 8;

		virtual wxCoord OnGetRowHeight(size_t row) const;
		virtual wxCoord OnGetColumnWidth(size_t row) const;

		void OnDraw(wxDC& dc);
		void OnPaint(wxPaintEvent& event);
		void OnMouseWheel(wxMouseEvent& event);

		DECLARE_EVENT_TABLE();
};
