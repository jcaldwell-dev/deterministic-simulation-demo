#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Represents a simple Simulation Entity with deterministic state
struct Entity
{
    int Id = 0;
    std::string Name;
    float Position = 0.0f;
    float Velocity = 0.0f;
};

// Represents a recorded Simulation Event for reproducible Inspection
struct SimulationEvent
{
    int StepIndex = 0;
    std::string Message;
};

// Updates an entity using Fixed Timestep movement
void UpdateEntity(Entity& entity, float fixedDeltaTime)
{
    entity.Position += entity.Velocity * fixedDeltaTime;
}

// Checks whether two entities are close enough to Interact
bool AreEntitiesInRange(const Entity& first, const Entity& second, float interactionRange)
{
    return std::fabs(first.Position - second.Position) <= interactionRange;
}

int main()
{
    constexpr float FixedDeltaTime = 0.1f;
    constexpr int TotalSteps = 20;
    constexpr float InteractionRange = 0.25f;

    Entity attacker{ 1, "Attacker", 0.0f, 0.5f };
    Entity target{ 2, "Target", 1.0f, -0.25f };

    std::vector<SimulationEvent> eventLog;

    for (int stepIndex = 0; stepIndex < TotalSteps; ++stepIndex)
    {
        // Deterministic update order is Intentional & Stable
        UpdateEntity(attacker, FixedDeltaTime);
        UpdateEntity(target, FixedDeltaTime);

        if (AreEntitiesInRange(attacker, target, InteractionRange))
        {
            eventLog.push_back({
                stepIndex,
                attacker.Name + " interacted with " + target.Name
            });
        }

        std::cout << "Step " << stepIndex
                  << " | Attacker Position: " << attacker.Position
                  << " | Target Position: " << target.Position
                  << '\n';
    }

    std::cout << "\nEvent Log\n";
    std::cout << "---------\n";

    if (eventLog.empty())
    {
        std::cout << "No interaction events recorded.\n";
    }
    else
    {
        for (const SimulationEvent& event : eventLog)
        {
            std::cout << "Step " << event.StepIndex
                      << ": " << event.Message << '\n';
        }
    }

    return 0;
}