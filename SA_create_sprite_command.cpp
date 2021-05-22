#include "SA_create_sprite_command.h"
#include "SA_sprite.h"
#include "SA_frame.h"
#include "SA_sprite_frame.h"

SACreateSpriteCommand::SACreateSpriteCommand(const wxString& name,
		CreateSpriteOperation op,
		SADocument* pDoc,
		SAFrame* pParentFrame)
{
	m_pDoc = pDoc;
	m_pParentFrame = pParentFrame;
	m_op = op;
}

SACreateSpriteCommand::~SACreateSpriteCommand()
{
}

bool SACreateSpriteCommand::Do()
{
	return DoOrUndo(m_op);
}

bool SACreateSpriteCommand::Undo()
{
	return DoOrUndo(m_op);
}

bool SACreateSpriteCommand::DoOrUndo(CreateSpriteOperation op)
{
	wxASSERT(m_pDoc != NULL);

	switch(op)
	{
		case CREATE_SPRITE:
			{
				// add the new sprite
				m_pDoc->GetSprites().Append(new SASprite());

				// create frame
				SASpriteFrame *f = new SASpriteFrame(m_pParentFrame, "Sprite");
				f->Show();
				break;
			}

		case UNDO_CREATE_SPRITE:
			{
				wxObjectListNode* node = m_pDoc->GetSprites().GetLast();
				if(node == NULL) break;
				SASprite* pTemp = (SASprite *) node->GetData();
				m_pDoc->GetSprites().pop_back();
				delete pTemp;
				break;
			}
	}

	m_pDoc->Modify(true);
	m_pDoc->UpdateAllViews();

	return true;
}

