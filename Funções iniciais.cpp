#include <cstdint>

namespace ArceusFF::FuncoesIniciais {
    struct VetorXYVZ {
        float x;
        float v;
        float y;
        float z;
    };

    struct ConfigInicial {
        bool no_recoil;
        bool manter_disparos_na_cabeca;
        bool remover_tremedeiras;
        bool brutle_aimlock;
        std::uintptr_t offset_recoil_pitch = 0x004A1B20;
        std::uintptr_t offset_head_anchor_z = 0x004A1F80;
        std::uintptr_t offset_pixel_jitter_xy = 0x004A2310;
        std::uintptr_t offset_aim_lock_vz = 0x004A2790;
    };

    inline VetorXYVZ AplicarEstabilizacaoCabeca(VetorXYVZ alvo, const ConfigInicial& cfg) {
        if (cfg.no_recoil) {
            alvo.y *= 0.85f;
            alvo.v *= 0.85f;
        }
        if (cfg.remover_tremedeiras) {
            alvo.x = static_cast<float>(static_cast<int>(alvo.x));
            alvo.v = static_cast<float>(static_cast<int>(alvo.v));
        }
        if (cfg.manter_disparos_na_cabeca || cfg.brutle_aimlock) {
            alvo.z = alvo.z; // Mantém referência de altura da cabeça sem ultrapassar
        }
        return alvo;
    }
}
