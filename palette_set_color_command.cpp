#include "palette_set_color_command.h"

PaletteSetColorCommand::PaletteSetColorCommand(const wxString& name,
		PaletteSetColorOperation op,
		SADocument* pDoc,
		SAPalette* pPalette,
		wxColor color,
		int8_t nIndex)
{
	m_pDoc = pDoc;
	m_pPalette = pPalette;
	m_op = op;
	m_Color = color;
	m_nIndex = nIndex;
}

PaletteSetColorCommand::~PaletteSetColorCommand()
{
}

bool PaletteSetColorCommand::Do()
{
	return DoOrUndo(m_op);
}

bool PaletteSetColorCommand::Undo()
{
	return DoOrUndo(m_op);
}

bool PaletteSetColorCommand::DoOrUndo(PaletteSetColorOperation op)
{
	wxASSERT(m_pPalette != NULL);

	// in both cases, set m_Color to the previous value so the command can be
	// undone or redone
	wxColor prevColor = m_pPalette->GetColors()[m_nIndex];
	m_pPalette->GetColors()[m_nIndex] = wxColor(m_Color);
	m_Color = wxColor(prevColor);

	// do not change the size of the palette's colors array, or else we will
	// need to store that information too.  Instead, leave it alone and check
	// the size on other palette operations

	m_pDoc->Modify(true);
	m_pDoc->UpdateAllViews();

	return true;
}

