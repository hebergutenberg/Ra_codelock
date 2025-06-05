#ifdef CodeLock
modded class ActionConstructor
{   
    override void RegisterActions( TTypenameArray actions )
    {
        super.RegisterActions( actions );
        
        actions.Insert(ActionInteractLockOnNMCBRST);
        actions.Insert(ActionAttachCodeLockToNMCBRST);
        actions.Insert(ActionManageLockOnNMCBRST);
        actions.Insert(ActionLockAdminOnNMCBRST);
    };
};     
#endif