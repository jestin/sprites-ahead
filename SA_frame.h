#ifndef SA_FRAME_H
#define SA_FRAME_H

#include <wx/wx.h>
#include <wx/docmdi.h>
#include "SA_view.h"

class SAView;

class SAFrame : public wxDocMDIParentFrame
{
	public:
		SAFrame(wxDocManager* pManager,
				wxFrame* pFrame,
				wxWindowID id,
				const wxString& title,
				const wxPoint& pos,
				const wxSize& size,
				long type);

		void SetView(SAView* view) { m_pView = view; }
		SAView* GetView() const { return m_pView; }

	private:
		void OnMenuNewProject(wxCommandEvent& event);
		void OnMenuNewSprite(wxCommandEvent& event);
		void OnMenuNewPalette(wxCommandEvent& event);
		void OnMenuOpen(wxCommandEvent& event);
		void OnMenuSave(wxCommandEvent& event);
		void OnMenuExit(wxCommandEvent& event);
		void OnMenuAbout(wxCommandEvent& event);

	private:
		SAView* m_pView;

		wxDECLARE_EVENT_TABLE();
};

#endif //MAIN_FRAME_H
