#ifndef SAVIEW_H
#define SAVIEW_H

#include <wx/wx.h>
#include <wx/docview.h>
#include "SA_frame.h"

class SAFrame;

class SAView : public wxView
{
	DECLARE_DYNAMIC_CLASS(SAView)
	DECLARE_EVENT_TABLE()

	public:
		SAView();
		~SAView();

		// Overrides
		virtual bool OnCreate(wxDocument* pDoc, long flags);
		virtual void OnDraw(wxDC* pDC);
		virtual void OnUpdate(wxView* pSender, wxObject* pHint = NULL);
		virtual bool OnClose(bool deleteWindow = true);

		// Event Handlers
		void OnCreatePalette(wxCommandEvent& event);
		void OnCreateSprite(wxCommandEvent& event);

	private:
		SAFrame* m_pFrame;
};

#endif // SAVIEW_H

