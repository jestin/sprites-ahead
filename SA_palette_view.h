#ifndef SAPALETTEVIEW_H
#define SAPALETTEVIEW_H

#include <wx/wx.h>
#include <wx/docview.h>
#include "SA_document.h"
#include "palette_set_size_command.h"
#include "palette_set_color_command.h"

// forward declare to avoid circular reference
class SAPaletteFrame;

class SAPaletteView : public wxView
{
	DECLARE_DYNAMIC_CLASS(SAPaletteView)
	DECLARE_EVENT_TABLE()

	public:
		SAPaletteView();
		~SAPaletteView();

		// Overrides
		virtual bool OnCreate(wxDocument* pDoc, long flags);
		virtual void OnDraw(wxDC* pDC);
		virtual void OnUpdate(wxView* pSender, wxObject* pHint = NULL);
		virtual bool OnClose(bool deleteWindow = true);

		// event handlers
		void OnSetSize(wxCommandEvent& event);

	private:
		SAPalette* m_pPalette;
		SAPaletteFrame* m_pFrame;
};

#endif // SAPALETTEVIEW_H

