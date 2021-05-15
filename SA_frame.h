#ifndef SA_FRAME_H
#define SA_FRAME_H

#include <wx/wx.h>

class SAFrame;

class SAFrame : public wxMDIParentFrame
{
	public:
		SAFrame();

	private:
		void OnMenuNewSprite(wxCommandEvent& event);
		void OnMenuNewPalette(wxCommandEvent& event);
		void OnMenuOpen(wxCommandEvent& event);
		void OnMenuSave(wxCommandEvent& event);
		void OnMenuExit(wxCommandEvent& event);
		void OnMenuAbout(wxCommandEvent& event);

		wxDECLARE_EVENT_TABLE();
};

#endif //MAIN_FRAME_H
