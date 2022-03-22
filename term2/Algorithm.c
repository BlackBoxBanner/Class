/*  Algorithm 
    1. Insert new node into a tree (make the tree unbalance)
    2. Check balance node (balance factor = {-1,0,1})
    3. Check child node to find a rotation (have 4 cases)
        - If it was left sub tree of the left child, it's LL Rotation
        - If it was right sub tree of the right child, it's RR Rotation
        - If it was right sub tree of the left child, it's LR Rotation
        - If it was left sub tree of the right child, it's RL Rotation
    4. Rotation

    insert(TREE,VAL)
    Step1:  if TREE = NULL
                Allocate memory for TREE
                SET TREE->data = VAL
                SET TREE->LEFT = TREE->RIGHT = NULL
                SET TREE->Height = 1
            if VAL < TREE->data
                TREE->LEFT = insert(TREE->LEFT,VAL)
            else if VAL > TREE->VAL
                TREE->RIGHT = insert(TREE->RIGHT,VAL)   
            else return TREE

            [CHECK 4 CASES]
            TREE->Height = 1 + MAX(Height(TREE->LEFT),Height(TREE->RIGHT))
            BAL = getBalance(TREE)
            [LL Rotatioon]
            if BAL > 1 AND VAL < TREE->LEFT->VAL
                return RightRotate(TREE)
            [RR Rotation]
            if BAL < -1 AND VAL > TREE->RIGHT->VAL
                return LeftRotate(TREE)
            [LR Rotation]
            if BAL > 1 AND VAL > TREE->LEFT->VAL
                TREE->LEFT = LeftRotate(TREE->LEFT)
                return RightRotate(TREE)
            [RL Rotation]
            if BAL < -1 AND VAL < TREE->LEFT->VAL
                TREE->RIGHT = RightRotate(TREE->Right)
                return LeftRotate(TREE)
            return TREE
    Step2: END  

    RightRotate(STRUCT NODE *Y)
    Step1:  SET *X = Y->LEFT
            SET *T2 = X->RIGHT
            SET X->RIGHT = Y
            SET Y->LEFT = T2
            return X
    Step2:  END

    LeftRotate(STRUCT NODE *x)
    Step1:  SET *Y = X->RIGHT
            SET *T2 = Y->LEFT
            SET Y->LEFT = X
            SET X->RIGHT = T2
            return Y
    Step2:  END  
*/  


