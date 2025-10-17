#include <Arduino.h>
#include <LinkedList.h>
#include "Animation.h"

/**
 * @brief Tree of animations mapped to button presses
 */
class AnimationTree
{
private:
    AnimationTreeNode *_root;

public:
    /**
     * @brief Construct a new Animation Tree object
     *
     * @param root The root of the tree
     */
    AnimationTree(AnimationTreeNode *root)
        : _root(root)
    {
    }

    /**
     * @brief Get the animation based on the given path
     *
     * @param path The path of inputs
     * @return A pointer to the corresponding animation
     */
    Animation *getAnimation(LinkedList<bool> *path)
    {
        auto node = _root;

        // Navigate down the tree based on the given path
        for (int i = 0; i < path->size(); i++)
        {
            auto item = path->get(i);

            if (item)
                node = node->on;
            else
                node = node->off;

            if (node == nullptr)
                return nullptr;
        }

        return node->animation;
    }
};

/**
 * @brief A node on the animation tree
 */
struct AnimationTreeNode
{
public:
    /// @brief The child of this node corresponding to the on input
    AnimationTreeNode *on;
    /// @brief The child of this node corresponding to the off input
    AnimationTreeNode *off;
    /// @brief The animation associated with this node
    Animation *animation;
};
