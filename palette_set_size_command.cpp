#include "palette_set_size_command.h"

PaletteSetSizeCommand::PaletteSetSizeCommand(const wxString& name,
		PaletteSetSizeOperation op,
		SADocument* pDoc,
		SAPalette* pPalette,
		int8_t nColors)
	: wxCommand(true, name)
{
	m_pDoc = pDoc;
	m_pPalette = pPalette;
	m_op = op;
	m_nColors = nColors;
}

PaletteSetSizeCommand::~PaletteSetSizeCommand()
{
}

bool PaletteSetSizeCommand::Do()
{
	return DoOrUndo(m_op);
}

bool PaletteSetSizeCommand::Undo()
{
	return DoOrUndo(m_op);
}

bool PaletteSetSizeCommand::DoOrUndo(PaletteSetSizeOperation op)
{
	wxASSERT(m_pPalette != NULL);

	// in both cases, set m_nColors to the previous value so the command can be
	// undone or redone
	int8_t nPrev = m_pPalette->GetNumColors();
	m_pPalette->SetNumColors(m_nColors);
	m_nColors = nPrev;

	// do not change the size of the palette's colors array, or else we will
	// need to store that information too.  Instead, leave it alone and check
	// the size on other palette operations

	m_pDoc->Modify(true);
	m_pDoc->UpdateAllViews();

	return true;
}
