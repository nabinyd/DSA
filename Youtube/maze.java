import java.util.ArrayList;

public class maze {

    public static void main(String[] args) {
        System.out.println(count(4, 4));
        path("", 4, 4);
        System.out.println(pathRet("", 4, 4));
        System.out.println(pathRetDiag("", 3, 3));

    }

    static int count(int r, int c) {
        if (r == 1 || c == 1) {
            return 1;
        }

        int left = count(r - 1, c);
        int right = count(r, c - 1);
        return left + right;
    }

    static void path(String p, int r, int c) {
        if (r == 1 && c == 1) {
            System.err.println(p);
            return;
        }

        if (r > 1) {
            path(p + 'D', r - 1, c);
        }
        if (c > 1) {
            path(p + "R", r, c - 1);
        }
    }

    static ArrayList<String> pathRet(String p, int r, int c) {
        if (r == 1 && c == 1) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        ArrayList<String> list = new ArrayList<>();

        if (r > 1) {
            list.addAll(pathRet(p + 'D', r - 1, c));
        }
        if (c > 1) {
            list.addAll(pathRet(p + "R", r, c - 1));
        }
        return list;
    }

    /**
     * @param p
     * @param r
     * @param c
     * @return
     */
    static ArrayList<String> pathRetDiag(String p, int r, int c) {
        if (r == 1 && c == 1) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        ArrayList<String> list = new ArrayList<>();
        if (r > 1 && c > 1) {
            list.addAll(pathRetDiag(p + 'D', r - 1, c - 1));
        }

        if (r > 1) {
            list.addAll(pathRetDiag(p + 'D', r - 1, c));
        }
        if (c > 1) {
            list.addAll(pathRetDiag(p + "R", r, c - 1));
        }
        return list;
    }

}
