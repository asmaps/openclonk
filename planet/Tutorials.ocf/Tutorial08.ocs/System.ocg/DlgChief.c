// A chief which tells you about the flood and the pump.

#appendto Dialogue

public func Dlg_Chief_Init(object clonk)
{
	AddEffect("IntChief", clonk, 100, 5, this);
	return true;
}

public func Dlg_Chief_1(object clonk)
{
	var found_lorry = false;
	for (var lorry in FindObjects(Find_ID(Lorry), Find_InRect(AbsX(0), AbsY(160), 280, 40)))
		if (ObjectCount(Find_ID(Metal), Find_Container(lorry)) >= 32)
			found_lorry = true;

	if (found_lorry)
	{
		MessageBox("$DlgChiefLorry$", clonk, clonk);
		SetDialogueProgress(8);
	}
	else	
	{	
		MessageBox("$DlgChiefHello$", clonk, dlg_target);
	}
	return true;
}

public func Dlg_Chief_2(object clonk)
{
	MessageBox("$DlgChiefReply$", clonk, clonk);
	return true;
}

public func Dlg_Chief_3(object clonk)
{
	MessageBox("$DlgChiefNoMetal$", clonk, dlg_target);
	return true;
}

public func Dlg_Chief_4(object clonk)
{
	MessageBox("$DlgChiefHelp$", clonk, clonk);
	return true;
}

public func Dlg_Chief_5(object clonk)
{
	MessageBox("$DlgChiefAppreciation$", clonk, dlg_target);
	return true;
}

public func Dlg_Chief_6(object clonk)
{
	MessageBox("$DlgChiefReward$", clonk, clonk);
	return true;
}

public func Dlg_Chief_7(object clonk)
{
	MessageBox("$DlgChiefMetal$", clonk, dlg_target);
	StopDialogue();
	SetDialogueProgress(1);
	return true;
}

public func Dlg_Chief_8(object clonk)
{
	MessageBox("$DlgChiefKeepLorry$", clonk, dlg_target);
	StopDialogue();
	SetDialogueProgress(9);
	GameCall("OnGoalCompleted", clonk->GetOwner());
	return true;
}

public func Dlg_Chief_9(object clonk)
{
	MessageBox("$DlgChiefReally$", clonk, dlg_target);
	StopDialogue();
	SetDialogueProgress(9);
	return true;
}

public func Dlg_Chief_Closed(object clonk)
{
	GameCall("OnHasTalkedMineChief", clonk);
	return true;
}

public func FxIntChiefStart(object target, proplist effect, int temp)
{
	if (temp)
		return FX_OK;
	return FX_OK;
}

public func FxIntChiefTimer(object target, proplist effect, int time)
{
	return FX_OK;
}
