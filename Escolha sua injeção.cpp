#include <string>

namespace ArceusFF::Injecao {
    enum class AlvoJogo {
        FreeFirePadrao,
        FreeFireMax
    };

    struct PacoteInjecao {
        AlvoJogo alvo;
        std::string esquema_abertura;
        bool estado_no_recoil;
        bool estado_manter_cabeca;
        bool estado_remover_tremedeiras;
        bool estado_brutle_aimlock;
        bool estado_aim_assist;
        bool estado_remover_delay;
        bool estado_controle_mira;
    };

    inline std::string ObterEsquema(AlvoJogo alvo) {
        return (alvo == AlvoJogo::FreeFireMax) ? "freefiremax://" : "freefire://";
    }
}
