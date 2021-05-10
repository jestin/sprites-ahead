#include "SA_palette_view.h"

IMPLEMENT_DYNAMIC_CLASS(SAPaletteView, wxView)

BEGIN_EVENT_TABLE(SAPaletteView, wxView)
	EVT_MENU(PaletteSetSizeCommand::PALETTE_SET_SIZE, SAPaletteView::OnSetSize)
END_EVENT_TABLE()


SAPaletteView::SAPaletteView()
{
	m_pFrame = NULL;
}

SAPaletteView::~SAPaletteView()
{
}

bool SAPaletteView::OnCreate(wxDocument *pDoc, long flags)
{
	// Associate the correct frame with this view
	return true;
}

void SAPaletteView::OnDraw(wxDC* pDC)
{
	pDC->Clear();
}

void SAPaletteView::OnUpdate(wxView *pSender, wxObject *pHint)
{
	if(m_pFrame && m_pFrame->GetCanvas())
	{
		m_pFrame->GetCanvas()->Refresh();
	}
}

bool SAPaletteView::OnClose(bool WXUNUSED(deleteWindow))
{
	return true;
}

void SAPaletteView::OnSetSize(wxCommandEvent &event)
{
	SADocument* pDoc = (SADocument *) GetDocument();
	pDoc->GetCommandProcessor()->Submit(
			new PaletteSetSizeCommand(
				"Set Palette Size",
				PaletteSetSizeCommand::PALETTE_SET_SIZE,
				pDoc,
				m_pPalette,
				/* TODO: replace with value from event */ 8)
			);
}
