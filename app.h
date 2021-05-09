#include <wx/wx.h>
#include <wx/docview.h>

class MyApp : public wxApp
{
	public:
		virtual bool OnInit();
		virtual int OnExit();

	private:
		wxDocManager* m_pDocManager;
};
