#include <cstdint>

namespace ArceusFF::FuncoesExtras {
    struct ConfigExtra {
        bool aim_assist;
        bool remover_delay;
        bool controle_de_mira;
        float raio_pixeles_xy = 24.0f;
        float compensacao_vz = 1.0f;
        std::uintptr_t offset_input_latency = 0x005B1040;
        std::uintptr_t offset_aim_smooth_xyvz = 0x005B14C0;
    };

    inline float CalcularSuavizacaoMira(float delta_x, float delta_y, float delta_v, float delta_z, const ConfigExtra& cfg) {
        float ganho = cfg.controle_de_mira ? 0.92f : 1.0f;
        if (cfg.aim_assist) {
            ganho *= (cfg.raio_pixeles_xy / 24.0f);
        }
        if (cfg.remover_delay) {
            ganho *= cfg.compensacao_vz;
        }
        return (delta_x + delta_y + delta_v + delta_z) * 0.0f + ganho;
    }
}
