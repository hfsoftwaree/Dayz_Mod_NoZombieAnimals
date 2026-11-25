class CfgPatches
{
    class ZHF_NoZombieAnimals  
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Scripts", "DZ_data_aiconfigs"};
    };
};

class CfgMods
{
    class ZHF_NoZombieAnimals  
    {
        dir = "ZHF_NoZombieAnimals";
        picture = "";
        action = "";
        hideName = 0;
        hidePicture = 1;
        name = "ZHF No Zombie Animals";
        credits = "HF";
        author = "HF";
        authorID = "0";
        version = "1.0";
        extra = 0;
        type = "mod";
        dependencies[] = {"World"};

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] =
                {
                    "ZHF_NoZombieAnimals/scripts/4_World/Entities/Infected"
                };
            };
        };
    };
};

class AIParams
{
    class AgentTeams
    {
        TeamList[] =
        {
            "Player",
            "BigGame",
            "Zombies",
            "Predator",
            "AmbientLife"
        };

        class Player
        {
            friends[] = {"Player"};
        };

        class Predator
        {
            friends[] = {"Predator", "AmbientLife"};
        };

        class BigGame
        {
            friends[] = {"BigGame", "AmbientLife"};
        };

        class Zombies
        {
            friends[] =
            {
                "Zombies",
                "AmbientLife",
                "BigGame",
                "Predator"
            };
        };

        class AmbientLife
        {
            friends[] = {"AmbientLife"};
        };
    };
};