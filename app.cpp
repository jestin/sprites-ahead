#include "app.h"
#include "SA_frame.h"
#include "SA_document.h"
#include "SA_palette_view.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	m_pDocManager = new wxDocManager();

	// Create a template
	(void) new wxDocTemplate(
			m_pDocManager,
			wxT("Sprites Ahead"),
			wxT("*.pfh"),
			wxT(""),
			wxT("pfh"),
			wxT("Sprites Ahead Document"),
			wxT("Palette View"),
			CLASSINFO(SADocument),
			CLASSINFO(SAPaletteView));

#ifdef __WXMAC__
	wxFileName::MacRegisterDefaultTypeAndCreator(wxT("pfh"), 'WXMB', 'WXMA');
#endif

	SAFrame * frame = new SAFrame();
	frame->Show(true);
	return true;
}

int MyApp::OnExit()
{
	delete m_pDocManager;
	return 0;
}
