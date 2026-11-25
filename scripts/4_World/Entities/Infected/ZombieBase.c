modded class ZombieBase
{
    override void Init()
    {
        super.Init();

        for (int i = m_TargetableObjects.Count() - 1; i >= 0; i--)
        {
            if (m_TargetableObjects[i].IsInherited(AnimalBase))
                m_TargetableObjects.Remove(i);
        }
    }

    override bool ModCommandHandlerBefore(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
    {
        DayZInfectedInputController ic = GetInputController();
        if (ic)
        {
            EntityAI target = ic.GetTargetEntity();
            if (target && target.IsInherited(AnimalBase))
            {
                m_ActualTarget = null;
                return true;
            }
        }

        return false;
    }

    override bool ChaseAttackLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
    {
        EntityAI target = pInputController.GetTargetEntity();
        if (target && target.IsInherited(AnimalBase))
            return false;

        return super.ChaseAttackLogic(pCurrentCommandID, pInputController, pDt);
    }

    override bool FightAttackLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
    {
        EntityAI target = pInputController.GetTargetEntity();
        if (target && target.IsInherited(AnimalBase))
            return false;

        return super.FightAttackLogic(pCurrentCommandID, pInputController, pDt);
    }
}