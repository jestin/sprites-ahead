#ifndef SAPALETTECANVAS_H
#define SAPALETTECANVAS_H

#include <wx/wx.h>
#include <wx/vscroll.h>
#include "SA_palette_view.h"

class SAPaletteCanvas : public wxHVScrolledWindow
{
	public:
		SAPaletteCanvas(wxWindow *parent);
		~SAPaletteCanvas();

		// Overrides
		virtual void OnDraw(wxDC& dc);

		// Accessors
		void SetView(SAPaletteView* pView) { m_pView = pView; }
		SAPaletteView* GetView() const { return m_pView; }

		// Event Handlers
		void OnMouseEvent(wxMouseEvent& event);

	private:
		SAPaletteView* m_pView;

	private:
		DECLARE_EVENT_TABLE();
};

#endif // SAPALETTECANVAS_H

