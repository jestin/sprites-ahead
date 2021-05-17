#include "app.h"
#include "SA_frame.h"
#include "SA_document.h"
#include "SA_view.h"

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
			wxT("Sprites Ahead View"),
			CLASSINFO(SADocument),
			CLASSINFO(SAView));

#ifdef __WXMAC__
	wxFileName::MacRegisterDefaultTypeAndCreator(wxT("pfh"), 'WXMB', 'WXMA');
#endif

	m_pDocManager->SetMaxDocsOpen(1);

	SAFrame * frame = new SAFrame(m_pDocManager,
			NULL,
			wxID_ANY,
			wxT("Sprites Ahead"),
			wxPoint(0, 0),
			wxSize(500, 400),
			wxDEFAULT_FRAME_STYLE);

	frame->Show(true);

	// start the app with a fresh document
	m_pDocManager->CreateNewDocument();

	return true;
}

int MyApp::OnExit()
{
	delete m_pDocManager;
	return 0;
}
