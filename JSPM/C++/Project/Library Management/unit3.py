from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import cm
from reportlab.lib import colors
from reportlab.platypus import (
    SimpleDocTemplate,
    Paragraph,
    Spacer,
    HRFlowable,
    Table,
    TableStyle,
    PageBreak,
)
from reportlab.lib.enums import TA_CENTER, TA_JUSTIFY
from reportlab.pdfgen import canvas

# =============================================================================
# OUTPUT FILE
# =============================================================================

OUTPUT = "Unit3_Exam_QA.pdf"

# =============================================================================
# DOCUMENT SETUP
# =============================================================================

doc = SimpleDocTemplate(
    OUTPUT,
    pagesize=A4,
    leftMargin=2.2 * cm,
    rightMargin=2.2 * cm,
    topMargin=2 * cm,
    bottomMargin=2 * cm,
    title="Unit III – Managerial Ethics and Leadership: Exam Q&A",
    author="Study Guide",
)

# =============================================================================
# COLORS
# =============================================================================

NAVY = colors.HexColor("#1B3A6B")
BLUE_LIGHT = colors.HexColor("#E6F1FB")
BLUE_MID = colors.HexColor("#185FA5")
ORANGE = colors.HexColor("#E07B2A")
ORANGE_BG = colors.HexColor("#FFF3E0")
GREEN = colors.HexColor("#2E7D32")
GREEN_BG = colors.HexColor("#EAF3DE")
GRAY_DARK = colors.HexColor("#333333")
GRAY_MID = colors.HexColor("#666666")
GRAY_LIGHT = colors.HexColor("#F5F5F5")
WHITE = colors.white
DIVIDER = colors.HexColor("#CCCCCC")

# =============================================================================
# STYLES
# =============================================================================

base = getSampleStyleSheet()


def make_style(name, **kwargs):
    return ParagraphStyle(name, **kwargs)


cover_title = make_style(
    "cover_title",
    fontName="Helvetica-Bold",
    fontSize=24,
    textColor=WHITE,
    alignment=TA_CENTER,
    leading=30,
    spaceAfter=6,
)

cover_sub = make_style(
    "cover_sub",
    fontName="Helvetica",
    fontSize=13,
    textColor=colors.HexColor("#BDD9F7"),
    alignment=TA_CENTER,
    leading=18,
)

section_header = make_style(
    "section_header",
    fontName="Helvetica-Bold",
    fontSize=13,
    textColor=WHITE,
    leading=18,
)

q_label = make_style(
    "q_label",
    fontName="Helvetica-Bold",
    fontSize=10,
    textColor=WHITE,
    leading=14,
)

question_text = make_style(
    "question_text",
    fontName="Helvetica-Bold",
    fontSize=11,
    textColor=NAVY,
    leading=16,
    spaceAfter=4,
)

body = make_style(
    "body",
    fontName="Helvetica",
    fontSize=10,
    textColor=GRAY_DARK,
    leading=15,
    spaceAfter=3,
    alignment=TA_JUSTIFY,
)

bold_body = make_style(
    "bold_body",
    fontName="Helvetica-Bold",
    fontSize=10,
    textColor=GRAY_DARK,
    leading=15,
    spaceAfter=2,
)

bullet_body = make_style(
    "bullet_body",
    fontName="Helvetica",
    fontSize=10,
    textColor=GRAY_DARK,
    leading=15,
    leftIndent=14,
    spaceAfter=2,
    alignment=TA_JUSTIFY,
)

tip_text = make_style(
    "tip_text",
    fontName="Helvetica-Oblique",
    fontSize=9,
    textColor=GREEN,
    leading=13,
)

small_gray = make_style(
    "small_gray",
    fontName="Helvetica",
    fontSize=9,
    textColor=GRAY_MID,
    leading=13,
)

# =============================================================================
# HELPER FUNCTIONS
# =============================================================================


def spacer(h=0.3):
    return Spacer(1, h * cm)


def hr():
    return HRFlowable(
        width="100%",
        thickness=0.5,
        color=DIVIDER,
        spaceAfter=6,
        spaceBefore=6,
    )


def add_page_number(canvas_obj, doc_obj):
    page_num = canvas_obj.getPageNumber()
    canvas_obj.setFont("Helvetica", 9)
    canvas_obj.setFillColor(GRAY_MID)
    canvas_obj.drawRightString(
        A4[0] - 2 * cm,
        1 * cm,
        f"Page {page_num}",
    )


def question_block(qnum, marks, qtext, marks_str):
    header_color = BLUE_MID if marks == 5 else ORANGE
    bg_color = BLUE_LIGHT if marks == 5 else ORANGE_BG
    border_color = BLUE_MID if marks == 5 else ORANGE

    header = Table(
        [[
            Paragraph(f"Q{qnum}", q_label),
            Paragraph(marks_str, q_label),
        ]],
        colWidths=[doc.width * 0.90, doc.width * 0.10],
    )

    header.setStyle(TableStyle([
        ("BACKGROUND", (0, 0), (-1, -1), header_color),
        ("TEXTCOLOR", (0, 0), (-1, -1), WHITE),
        ("ALIGN", (1, 0), (1, 0), "RIGHT"),
        ("LEFTPADDING", (0, 0), (-1, -1), 8),
        ("RIGHTPADDING", (0, 0), (-1, -1), 8),
        ("TOPPADDING", (0, 0), (-1, -1), 5),
        ("BOTTOMPADDING", (0, 0), (-1, -1), 5),
    ]))

    body_tbl = Table(
        [[Paragraph(qtext, question_text)]],
        colWidths=[doc.width],
    )

    body_tbl.setStyle(TableStyle([
        ("BACKGROUND", (0, 0), (-1, -1), bg_color),
        ("BOX", (0, 0), (-1, -1), 0.7, border_color),
        ("LEFTPADDING", (0, 0), (-1, -1), 8),
        ("RIGHTPADDING", (0, 0), (-1, -1), 8),
        ("TOPPADDING", (0, 0), (-1, -1), 6),
        ("BOTTOMPADDING", (0, 0), (-1, -1), 6),
    ]))

    return [header, body_tbl]


def answer_label():
    tbl = Table(
        [[
            Paragraph(
                "MODEL ANSWER",
                make_style(
                    "answer_style",
                    fontName="Helvetica-Bold",
                    fontSize=9,
                    textColor=WHITE,
                ),
            )
        ]],
        colWidths=[doc.width],
    )

    tbl.setStyle(TableStyle([
        ("BACKGROUND", (0, 0), (-1, -1), colors.HexColor("#444444")),
        ("LEFTPADDING", (0, 0), (-1, -1), 8),
        ("TOPPADDING", (0, 0), (-1, -1), 4),
        ("BOTTOMPADDING", (0, 0), (-1, -1), 4),
    ]))

    return tbl


def tip_box(text):
    tbl = Table(
        [[Paragraph(f"Exam Tip: {text}", tip_text)]],
        colWidths=[doc.width],
    )

    tbl.setStyle(TableStyle([
        ("BACKGROUND", (0, 0), (-1, -1), GREEN_BG),
        ("BOX", (0, 0), (-1, -1), 0.5, GREEN),
        ("LEFTPADDING", (0, 0), (-1, -1), 8),
        ("RIGHTPADDING", (0, 0), (-1, -1), 8),
        ("TOPPADDING", (0, 0), (-1, -1), 5),
        ("BOTTOMPADDING", (0, 0), (-1, -1), 5),
    ]))

    return tbl


# =============================================================================
# STORY
# =============================================================================

story = []

# =============================================================================
# COVER PAGE
# =============================================================================

cover_tbl = Table(
    [
        [Paragraph("UNIT III", cover_sub)],
        [Paragraph("Managerial Ethics and Leadership", cover_title)],
        [Paragraph("End-Semester Exam — Question &amp; Answer Bank", cover_sub)],
        [Paragraph("5 Marks  |  10 Marks", cover_sub)],
    ],
    colWidths=[doc.width],
)

cover_tbl.setStyle(TableStyle([
    ("BACKGROUND", (0, 0), (-1, -1), NAVY),
    ("ALIGN", (0, 0), (-1, -1), "CENTER"),
    ("LEFTPADDING", (0, 0), (-1, -1), 20),
    ("RIGHTPADDING", (0, 0), (-1, -1), 20),
    ("TOPPADDING", (0, 0), (-1, -1), 14),
    ("BOTTOMPADDING", (0, 0), (-1, -1), 14),
]))

story.append(Spacer(1, 3 * cm))
story.append(cover_tbl)
story.append(spacer(1))

instructions_tbl = Table(
    [
        [Paragraph("<b>How to use this guide</b>", bold_body)],
        [Paragraph(
            "For <b>5-mark</b> answers: write 12–15 lines with intro, points, and conclusion.",
            body,
        )],
        [Paragraph(
            "For <b>10-mark</b> answers: write 30–35 lines with examples and frameworks.",
            body,
        )],
        [Paragraph(
            "Use Starbucks examples and named theories/frameworks whenever possible.",
            body,
        )],
    ],
    colWidths=[doc.width],
)

instructions_tbl.setStyle(TableStyle([
    ("BACKGROUND", (0, 0), (-1, -1), GRAY_LIGHT),
    ("BOX", (0, 0), (-1, -1), 1, NAVY),
    ("LEFTPADDING", (0, 0), (-1, -1), 10),
    ("RIGHTPADDING", (0, 0), (-1, -1), 10),
    ("TOPPADDING", (0, 0), (-1, -1), 5),
    ("BOTTOMPADDING", (0, 0), (-1, -1), 5),
]))

story.append(instructions_tbl)
story.append(PageBreak())

# =============================================================================
# SECTION A
# =============================================================================

section_a = Table(
    [[Paragraph("SECTION A — 5 MARK QUESTIONS", section_header)]],
    colWidths=[doc.width],
)

section_a.setStyle(TableStyle([
    ("BACKGROUND", (0, 0), (-1, -1), BLUE_MID),
    ("LEFTPADDING", (0, 0), (-1, -1), 12),
    ("TOPPADDING", (0, 0), (-1, -1), 8),
    ("BOTTOMPADDING", (0, 0), (-1, -1), 8),
]))

story.append(section_a)
story.append(spacer(0.4))

# =============================================================================
# QUESTION 1
# =============================================================================

story += question_block(
    1,
    5,
    "What is Business Ethics? Explain why ethics matters in business.",
    "[5M]",
)

story.append(spacer(0.2))
story.append(answer_label())
story.append(spacer(0.15))

story.append(Paragraph("<b>Introduction</b>", bold_body))

story.append(Paragraph(
    "Business ethics refers to moral principles and standards that guide "
    "behaviour in business organisations. Ethics determines how a company "
    "interacts with employees, customers, investors, suppliers, and society.",
    body,
))

story.append(Paragraph("<b>Importance of Ethics</b>", bold_body))

points = [
    "Builds trust and brand reputation.",
    "Reduces legal and regulatory risk.",
    "Improves employee morale and retention.",
    "Encourages long-term sustainability.",
    "Creates competitive advantage.",
]

for p in points:
    story.append(Paragraph(f"• {p}", bullet_body))

story.append(Paragraph("<b>Conclusion</b>", bold_body))

story.append(Paragraph(
    "Ethics is essential for sustainable business growth and stakeholder trust.",
    body,
))

story.append(spacer(0.15))

story.append(
    tip_box(
        "Mention Enron as an example of unethical business practices."
    )
)

story.append(spacer(0.5))
story.append(hr())

# =============================================================================
# QUESTION 2
# =============================================================================

story += question_block(
    2,
    5,
    "Explain the four ethical decision-making frameworks.",
    "[5M]",
)

story.append(spacer(0.2))
story.append(answer_label())
story.append(spacer(0.15))

frameworks = [
    ("Utilitarianism", "Greatest good for greatest number."),
    ("Deontology", "Focus on duty and moral rules."),
    ("Virtue Ethics", "Focus on moral character."),
    ("4V Model", "Values, Voice, Vision, and Virtue."),
]

for title, desc in frameworks:
    story.append(
        Paragraph(f"<b>{title}:</b> {desc}", bullet_body)
    )

story.append(spacer(0.15))

story.append(
    tip_box(
        "Write theorist names like Kant and Aristotle for extra marks."
    )
)

story.append(spacer(0.5))
story.append(hr())

# =============================================================================
# SECTION B
# =============================================================================

section_b = Table(
    [[Paragraph("SECTION B — 10 MARK QUESTIONS", section_header)]],
    colWidths=[doc.width],
)

section_b.setStyle(TableStyle([
    ("BACKGROUND", (0, 0), (-1, -1), ORANGE),
    ("LEFTPADDING", (0, 0), (-1, -1), 12),
    ("TOPPADDING", (0, 0), (-1, -1), 8),
    ("BOTTOMPADDING", (0, 0), (-1, -1), 8),
]))

story.append(section_b)
story.append(spacer(0.4))

# =============================================================================
# QUESTION 3
# =============================================================================

story += question_block(
    3,
    10,
    "Discuss Corporate Social Responsibility (CSR) and its importance.",
    "[10M]",
)

story.append(spacer(0.2))
story.append(answer_label())
story.append(spacer(0.15))

story.append(Paragraph("<b>Introduction</b>", bold_body))

story.append(Paragraph(
    "Corporate Social Responsibility (CSR) refers to the responsibility "
    "of businesses toward society and the environment.",
    body,
))

story.append(Paragraph("<b>Carroll’s Pyramid of CSR</b>", bold_body))

csr_points = [
    "Economic Responsibility",
    "Legal Responsibility",
    "Ethical Responsibility",
    "Philanthropic Responsibility",
]

for p in csr_points:
    story.append(Paragraph(f"• {p}", bullet_body))

story.append(Paragraph("<b>Starbucks Example</b>", bold_body))

story.append(Paragraph(
    "Starbucks follows ethical sourcing through its C.A.F.E. practices "
    "and invests in sustainability programs.",
    body,
))

story.append(Paragraph("<b>Conclusion</b>", bold_body))

story.append(Paragraph(
    "CSR improves reputation, customer trust, and long-term sustainability.",
    body,
))

story.append(spacer(0.15))

story.append(
    tip_box(
        "Mention Triple Bottom Line: People, Planet, Profit."
    )
)

story.append(spacer(0.5))

# =============================================================================
# FOOTER
# =============================================================================

story.append(hr())

footer_tbl = Table(
    [[
        Paragraph(
            "Unit III — Managerial Ethics and Leadership",
            small_gray,
        )
    ]],
    colWidths=[doc.width],
)

footer_tbl.setStyle(TableStyle([
    ("ALIGN", (0, 0), (-1, -1), "CENTER"),
]))

story.append(footer_tbl)

# =============================================================================
# BUILD PDF
# =============================================================================

doc.build(
    story,
    onFirstPage=add_page_number,
    onLaterPages=add_page_number,
)

print(f"PDF created successfully: {OUTPUT}")