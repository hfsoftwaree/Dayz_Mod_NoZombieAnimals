# 🐺 ZHF No Zombie Animals – Zumbis Ignoram Animais no DayZ

Mod para **DayZ Standalone** que impede que os **zumbis (infectados) ataquem ou persigam animais**. Combina uma alteração na configuração de IA (`AgentTeams`) com scripts que removem animais da lista de alvos do infectado.

---

## ✨ Funcionalidades

- 🧟 **Zumbis ignoram animais:** infectados deixam de tratar animais (`AnimalBase`) como alvo
- 🛑 **Bloqueio de ataques:** cancela a perseguição (`ChaseAttackLogic`) e o ataque corpo a corpo (`FightAttackLogic`) contra animais
- 🤝 **Equipes de IA ajustadas:** zumbis passam a ser "amigos" de `BigGame`, `Predator` e `AmbientLife` na configuração de IA
- 🧩 Usa `modded class`, sem substituir arquivos vanilla

---

## ⚙️ Como funciona

O mod age em duas camadas:

### 1. Configuração de IA (`config.cpp`)

Redefine as `AgentTeams` do jogo. Na equipe `Zombies`, a lista de amigos inclui as equipes de animais:

| Equipe | Amigos |
|---|---|
| `Player` | `Player` |
| `Predator` | `Predator`, `AmbientLife` |
| `BigGame` | `BigGame`, `AmbientLife` |
| `Zombies` | `Zombies`, `AmbientLife`, `BigGame`, `Predator` |
| `AmbientLife` | `AmbientLife` |

### 2. Scripts (`ZombieBase`)

| Método | Comportamento |
|---|---|
| `Init()` | Remove animais da lista `m_TargetableObjects` do infectado |
| `ModCommandHandlerBefore()` | Se o alvo atual for um animal, limpa o alvo (`m_ActualTarget = null`) |
| `ChaseAttackLogic()` | Não executa a perseguição se o alvo for um animal |
| `FightAttackLogic()` | Não executa o ataque se o alvo for um animal |

---

## 📁 Estrutura do projeto

```
ZHF_NoZombieAnimals/
├── config.cpp
└── scripts/
    └── 4_World/
        └── Entities/
            └── Infected/
                └── ZombieBase.c
```

> Ajuste os nomes conforme os arquivos reais do seu projeto.

---

## 🧰 Tecnologias

- Enforce Script (DayZ)
- Configuração de IA (`AIParams` / `AgentTeams`)
- Dependências: `DZ_Scripts`, `DZ_data_aiconfigs`

---

## 👤 Autor

Desenvolvido por **HF**.

