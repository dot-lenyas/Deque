
#include <iostream>

class Deque
{
private:
    int left, right;
    int* values;
    int size, fullness;



    void makeLeftShifts()
    {
        int shifts = (size - fullness) - 1;
        shifts == 0 ? shifts += 1 : shifts;
        for (int i = shifts + 1; i >= 0; i--)
        {
            values[i + shifts] = values[i];
            values[i] = -1;
        }
        left += shifts;
        right += shifts;
    }

    void makeRightShifts()
    {
        int shifts = (size - fullness) - 1;
        shifts == 0 ? shifts += 1 : shifts;
        for (int i = shifts + 1; i < size; i++)
        {
            values[i - shifts] = values[i];
            values[i] = -1;
        }
        right -= shifts;
        left -= shifts;
    }
public:
    int DEQUE_IS_FULL = 2;
    int DEQUE_IS_EMPTY = -1;
    int SUCCESS = 0;
    Deque(int size)
    {
        this->size = size;
        values = new int[size];
        for (int i = 0; i < size; ++i) {
            values[i] = -1;
        }
        left = (size / 2) - 1;
        right = size / 2;
        fullness = 0;
    }
    ~Deque()
    {

    }



    int push_left(int value)
    {
        if (fullness == size)
        {
           return DEQUE_IS_FULL;
        }
        else
        {
            if (left >= 0)
            {
                values[left] = value;
                left--;
                fullness++;
                return SUCCESS;
            }
            else if (left < 0)
            {
                makeLeftShifts();
                values[left] = value;
                left--;
                fullness++;
                return SUCCESS;
            }
        }
    }

    int push_right(int value)
    {
        if (fullness == size)
        {
            return DEQUE_IS_FULL;
        }
        else
        {
            if (right < size)
            {
                values[right] = value;
                right++;
                fullness++;
                return SUCCESS;
            }
            else if (right >= size)
            {
                makeRightShifts();
                right++;
                fullness++;
                return SUCCESS;
            }
        }
    }
    int pop_left()
    {
        if (fullness == 0)
        {
            return DEQUE_IS_EMPTY;
        }
        else
        {
                int temp = values[left + 1];
                left++;
                values[left] = -1;
                return temp;
        }
    }
    int pop_right()
    {
        if (fullness == 0)
        {
            return DEQUE_IS_EMPTY;
        }
        else
        {
            int temp = values[right - 1];
            right--;
            values[right] = -1;
            return temp;
        }

    }
    friend std::ostream& operator<< (std::ostream &out, const Deque &deque)
    {
        out << "Deque is" << std::endl;
        out << "|| ";
        for (int i = 0; i < deque.size; ++i)
        {
            if (deque.values[i] >= 0)
            {
                out << deque.values[i] << " || ";
            }
        }
        out << std::endl;

        return out;
    }
    Deque& operator= (const Deque& deque)
    {
        if (size == deque.size)
        {
            values = deque.values;
            left = deque.left;
            right = deque.right;
            fullness = deque.fullness;
        }
        else if (deque.size > size)
        {
            fullness = 0;
            for (int i = 0; i < size; ++i)
            {
                if (deque.values[i] >= 0)
                {
                    fullness++;
                    values[i] = deque.values[i];
                }
                else
                {
                    values[i] = -1;
                }
            }
            left = -1;
            for (int i = 0; i < size; ++i)
            {
                if (values[i] >= 0)
                {
                    break;
                }
                else
                {
                    left = i;
                }
            }
            right = size;
            for (int i = size - 1; i >= 0; --i)
            {
                if (values[i] >= 0)
                {
                    break;
                }
                else
                {
                    right = i;
                }
            }
        }
        else if (size > deque.size)
        {
            fullness = deque.fullness;
            for (int i = 0; i < size; ++i)
            {
                if (i < deque.size)
                {
                    values[i] = deque.values[i];
                }
                else
                {
                    values[i] = -1;
                }
            }
            left = -1;
            for (int i = 0; i < size; ++i)
            {
                if (values[i] >= 0)
                {
                    break;
                }
                else
                {
                    left = i;
                }
            }
            right = size;
            for (int i = size - 1; i >= 0; --i)
            {
                if (values[i] >= 0)
                {
                    break;
                }
                else
                {
                    right = i;
                }
            }
        }
        return *this;
    }

    



};


