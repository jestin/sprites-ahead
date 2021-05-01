#include <wx/wx.h>

class Main : public wxMDIParentFrame
{
	public:
		Main();

	private:
		void OnMenuNew(wxCommandEvent& event);
		void OnMenuOpen(wxCommandEvent& event);
		void OnMenuSave(wxCommandEvent& event);
		void OnMenuExit(wxCommandEvent& event);
		void OnMenuAbout(wxCommandEvent& event);

		void OnSelectColor(wxCommandEvent& event);

		wxDECLARE_EVENT_TABLE();
};

