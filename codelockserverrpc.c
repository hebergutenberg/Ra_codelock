#ifdef CodeLock
modded class CodeLockServerRPC : PluginBase
{
    override void OpenTarget(ItemBase target)
    {
        TentBase tent = TentBase.Cast(target);
        if (target.IsKindOf("NMCBRST_Openable_Base") && !target.IsOpen())
            target.Open();
        super.OpenTarget(target);
    }
};
#endif