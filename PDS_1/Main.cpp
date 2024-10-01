#include <iostream>
#include <string>

using namespace std;

// ������� ��� ���������
bool implication(bool p, bool q) {
    return !p || q;
}

// ������� ��� �������������
bool equivalence(bool p, bool q) {
    return implication(p, q) && implication(q, p);
}

// ���� ������� ��� ����������� �������� OR, AND, XOR
void bitwise_operations(const string& a, const string& b, string& or_result, string& and_result, string& xor_result) {
    int n = a.length();  // ������� �����
    or_result = "";
    and_result = "";
    xor_result = "";

    for (int i = 0; i < n; ++i) {
        // �������� OR
        if (a[i] == '1' || b[i] == '1')
            or_result += '1';
        else
            or_result += '0';

        // �������� A
        if (a[i] == '1' && b[i] == '1')
            and_result += '1';
        else
            and_result += '0';

        // �������� XOR
        if (a[i] != b[i])
            xor_result += '1';
        else
            xor_result += '0';
    }
}

int main() {
    bool p, q;

    // �������� ������� ��������� p � q
    cout << "Enter the truth value for p (0 or 1): ";
    cin >> p;
    cout << "Enter the truth value for q (0 or 1): ";
    cin >> q;

    // ���'������ (AND)
    bool conjunction = p && q;
    cout << "Conjunction (p ^ q): " << conjunction << endl;

    // ���'������ (OR)
    bool disjunction = p || q;
    cout << "Disjunction (p ? q): " << disjunction << endl;

    // ������������� "���" (XOR)
    bool exclusiveOr = p != q;
    cout << "Alternative \"OR\" (p ? q): " << exclusiveOr << endl;

    // ��������� p ? q
    bool impl_pq = implication(p, q);
    cout << "Implication (p -> q): " << impl_pq << endl;

    // ��������� q ? p
    bool impl_qp = implication(q, p);
    cout << "Implication (q -> p): " << impl_qp << endl;

    // ������������� (p ~ q)
    bool equiv = equivalence(p, q);
    cout << "Equivalence (p ~ q): " << equiv << endl;

    // ������ ��� ���� �����
    string a, b;
    cout << "\nEnter the first bit string: ";
    cin >> a;
    cout << "Enter the second bit string: ";
    cin >> b;

    // �������� �� ����� ����� �������� �������
    if (a.length() != 9 || b.length() != 9) {
        cout << "Error: Strings must be exactly 9 characters long";
        return 1;
    }

    string orResult, andResult, xorResult;
    bitwise_operations(a, b, orResult, andResult, xorResult);

    // ��������� ����������
    cout << "Result OR:  " << orResult << endl;
    cout << "Result AND: " << andResult << endl;
    cout << "Result XOR: " << xorResult << endl;

    return 0;
}
