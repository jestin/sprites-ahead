#include "set_active_palette_command.h"

SetActivePaletteCommand::SetActivePaletteCommand(const wxString& name,
		SetActivePaletteOperation op,
		SADocument* pDoc,
		int8_t nActivePalette)
{
	m_pDoc = pDoc;
	m_nActivePalette = nActivePalette;
}

SetActivePaletteCommand::~SetActivePaletteCommand()
{
}

bool SetActivePaletteCommand::Do()
{
	return DoOrUndo(m_op);
}

bool SetActivePaletteCommand::Undo()
{
	return DoOrUndo(m_op);
}

bool SetActivePaletteCommand::DoOrUndo(SetActivePaletteOperation WXUNUSED(op))
{
	wxASSERT(m_pDoc != NULL);

	int8_t nPrev = m_pDoc->GetActivePalette();
	m_pDoc->SetActivePalette(m_nActivePalette);
	m_nActivePalette = nPrev;

	m_pDoc->Modify(true);
	m_pDoc->UpdateAllViews();

	return true;
}
