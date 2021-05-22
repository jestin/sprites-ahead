#include "SA_view.h"
#include "SA_create_palette_command.h"
#include "SA_create_sprite_command.h"

IMPLEMENT_DYNAMIC_CLASS(SAView, wxView)

BEGIN_EVENT_TABLE(SAView, wxView)
	EVT_MENU(SACreatePaletteCommand::CREATE_PALETTE, SAView::OnCreatePalette)
END_EVENT_TABLE()

SAView::SAView()
{
}

SAView::~SAView()
{
}

bool SAView::OnCreate(wxDocument *pDoc, long flags)
{
	m_pFrame = (SAFrame *) wxApp::GetMainTopWindow();
	wxASSERT(m_pFrame != NULL);

	SetFrame((wxWindow *) m_pFrame);

	m_pFrame->SetView(this);

	Activate(true);

	pDoc->GetCommandProcessor()->Initialize();

	return true;
}

void SAView::OnDraw(wxDC *pDC)
{
}

void SAView::OnUpdate(wxView *pSender, wxObject* pHint)
{
}

bool SAView::OnClose(bool deleteWindow)
{
	return true;
}

void SAView::OnCreatePalette(wxCommandEvent &event)
{
	SADocument* pDoc = (SADocument*) GetDocument();
	if(pDoc == NULL) return;
	pDoc->GetCommandProcessor()->Submit(
			new SACreatePaletteCommand(wxT("Create Palette"),
				SACreatePaletteCommand::CREATE_PALETTE,
				pDoc,
				m_pFrame)
			);
}

void SAView::OnCreateSprite(wxCommandEvent &event)
{
	SADocument* pDoc = (SADocument*) GetDocument();
	if(pDoc == NULL) return;
	pDoc->GetCommandProcessor()->Submit(
			new SACreateSpriteCommand(wxT("Create Sprite"),
				SACreateSpriteCommand::CREATE_SPRITE,
				pDoc,
				m_pFrame)
			);
}
