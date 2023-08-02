#include <cstdio>

#include <daisy_seed.h>

#include <util/Terrarium.h>

//=============================================================================
void processAudioBlock(
    daisy::AudioHandle::InputBuffer in,
    daisy::AudioHandle::OutputBuffer out,
    size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        out[0][i] = in[0][i];
        out[1][i] = 0;
    }
}

//=============================================================================
int main()
{
    Terrarium terrarium;
    terrarium.Init();
    terrarium.seed.StartLog();
    terrarium.seed.StartAudio(processAudioBlock);

    constexpr int buffer_size = 5;
    char buffer[buffer_size] = {0};

    constexpr int update_rate = 60;
    constexpr int log_rate = update_rate / 5;

    int counter = 0;

    terrarium.Loop(update_rate, [&](){
        for (auto& knob : terrarium.knobs) (void)knob.Process();

        terrarium.leds[0].Set(terrarium.knobs[3].Value());
        terrarium.leds[1].Set(terrarium.knobs[5].Value());

        if (++counter > (update_rate/log_rate))
        {
            counter = 0;

            for (auto& knob : terrarium.knobs)
            {
                snprintf(buffer, buffer_size, "%4.2f", knob.Value());
                printf("%s\t", buffer);
                terrarium.seed.Print("%s\t", buffer);
            }

            for (auto& toggle : terrarium.toggles)
            {
                printf("_%s_", (toggle.Pressed() ? "/" : "\\"));
                terrarium.seed.Print("_%s_", (toggle.Pressed() ? "/" : "\\"));
            }

            for (auto& stomp : terrarium.stomps)
            {
                printf("\t[%s]", (stomp.Pressed() ? "x" : "_"));
                terrarium.seed.Print("\t[%s]", (stomp.Pressed() ? "x" : "_"));
            }

            printf("\n");
            terrarium.seed.PrintLine("");
        }
    });
}
