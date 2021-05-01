#include <wx/wx.h>

class MainFrame : public wxMDIParentFrame
{
	public:
		MainFrame();

	private:
		void OnMenuNew(wxCommandEvent& event);
		void OnMenuOpen(wxCommandEvent& event);
		void OnMenuSave(wxCommandEvent& event);
		void OnMenuExit(wxCommandEvent& event);
		void OnMenuAbout(wxCommandEvent& event);

		wxDECLARE_EVENT_TABLE();
};

