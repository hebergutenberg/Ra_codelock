#ifdef CodeLock
class ActionAttachCodeLockToNMCBRST : ActionSingleUseBase
{
    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }

    override string GetText()
    {
        return "Attach Codelock";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        ItemBase itemBase = ItemBase.Cast(target.GetObject());
        if (itemBase && (itemBase.IsKindOf("NMCBRST_Vault") || itemBase.IsKindOf("NMCBRST_Safe_Base") || itemBase.IsKindOf("NMCBRST_Rifle_Safe_Base")) || itemBase.IsKindOf("NMCBRST_MilitaryLocker_Base") || itemBase.IsKindOf("NMCBRST_MilitaryStorageCrate_Base"))
        {
            int slot = InventorySlots.GetSlotIdFromString(CLConst.clAttachment);
            if (slot == InventorySlots.INVALID)
                return false;
            if (!itemBase.IsCodeLocked() && itemBase.IsOpen())
                return true;
        }
        return false;
    }

    override void OnExecuteClient(ActionData action_data)
    {
        ItemBase itemBase = ItemBase.Cast(action_data.m_Target.GetObject());
        PlayerBase player = action_data.m_Player;
        ClearInventoryReservationEx(action_data);
        if (itemBase)
        {
            int slotID = InventorySlots.GetSlotIdFromString(CLConst.clAttachment);
            action_data.m_Player.PredictiveTakeEntityToTargetAttachmentEx(itemBase, action_data.m_MainItem, slotID);
            GetCLUIManager().ShowMenu(CLMENU.SET_CODE_MENU, itemBase);
        }
    }

    override void OnExecuteServer(ActionData action_data)
    {
        EntityAI target = EntityAI.Cast(action_data.m_Target.GetObject());
        PlayerIdentity playerId = action_data.m_Player.GetIdentity();
        if (target && playerId)
        {
            GetCodeLockLogger().WriteLog("attach", playerId, target.GetPosition());
        }
    }
};
#endif